#include "transform.h"
#include "syntactic.h"

#include <iostream>

const std::string Enum2Str[]{
        "LuaProgram",
        "LuaInt",
        "LuaMathOp"
};

std::string int2TransformType(int i) {
    return Enum2Str[i];
}

Transform::Transform() : Enum2stringSupport<ASTNode>(int2TransformType) {}

std::shared_ptr<ASTNodeTrunk> Transform::transformer(const std::shared_ptr<ASTNodeTrunk> &root) {
    ASTNodeTrunk *newRoot = travel(root);
    return std::shared_ptr<ASTNodeTrunk>(newRoot);
}

ASTNodeTrunk *Transform::travel(const std::shared_ptr<ASTNodeTrunk> &oldNode) {
    ASTNodeTrunk *newNode;
    if (oldNode->type == Syntactic::SyntacticType::Program) {
        newNode = new ASTNodeTrunk(LuaProgram, "");
    } else if (oldNode->type == Syntactic::SyntacticType::CallExpression) {
        std::string op;
        if (oldNode->value == "sub") {
            op = "-";
        } else if (oldNode->value == "add") {
            op = "+";
        } else {
            std::cerr << "Transformation: unknown call expression - " << oldNode->value << std::endl;
            std::abort();
        }
        newNode = new ASTNodeTrunk(LuaMathOp, op);
    } else {
        std::cerr << "Transformation: unexpected type in trunk node - " << oldNode->type << std::endl;
        std::abort();
    }

    for (const auto &node: oldNode->children) {
        if (node->isLeaf) {
            std::shared_ptr<ASTNodeLeaf> nodeLeaf = static_pointer_cast<ASTNodeLeaf>(node);
            newNode->children.emplace_back(travel(nodeLeaf));
        } else {
            std::shared_ptr<ASTNodeTrunk> nodeTrunk = static_pointer_cast<ASTNodeTrunk>(node);
            newNode->children.emplace_back(travel(nodeTrunk));
        }
    }

    return newNode;
}

ASTNodeLeaf *Transform::travel(const std::shared_ptr<ASTNodeLeaf> &oldNode) {
    ASTNodeLeaf *newNode;

    if (oldNode->type == Syntactic::SyntacticType::NumberLiteral) {
        newNode = new ASTNodeLeaf(LuaInt, oldNode->value);
    } else {
        std::cerr << "Transformation: unexpected type in leaf node - " << oldNode->type << std::endl;
        std::abort();
    }
    return newNode;
}


