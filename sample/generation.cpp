#include "generation.h"

#include <sstream>
#include <iostream>
#include "transform.h"


std::string Generation::generateCode(const std::shared_ptr<ASTNodeTrunk> &root) {
    std::stringstream ss;
    generate(root, ss);
    return ss.str();
}

void Generation::generate(const std::shared_ptr<ASTNodeTrunk> &node, std::stringstream &ss) {
    if (node->type == Transform::TransformType::LuaProgram) {
        for (const auto &child: node->children) {
            generateChild(child, ss);
            ss << std::endl;
        }
    } else if (node->type == Transform::TransformType::LuaMathOp) {
        if (node->children[0]) {
            generateChild(node->children[0], ss);
        } else {
            ss << "( ";
            generateChild(node->children[0], ss);
            ss << " )";
        }

        ss << " " << node->value << " ";

        if (node->children[1]->isLeaf) {
            generateChild(node->children[1], ss);
        } else {
            ss << "( ";
            generateChild(node->children[1], ss);
            ss << " )";
        }
    } else {
        std::cerr << "CodeGeneration: unexpected type in trunk node - " << node->type << std::endl;
        std::abort();
    }
}

void Generation::generate(const std::shared_ptr<ASTNodeLeaf> &node, std::stringstream &ss) {
    if (node->type == Transform::TransformType::LuaInt) {
        ss << node->value;
    } else {
        std::cerr << "Transformation: unexpected type in leaf node - " << node->type << std::endl;
        std::abort();
    }
}

void Generation::generateChild(const std::shared_ptr<ASTNode> &child, std::stringstream &ss) {
    if (child->isLeaf) {
        std::shared_ptr<ASTNodeLeaf> nodeLeaf = dynamic_pointer_cast<ASTNodeLeaf>(child);
        generate(nodeLeaf, ss);
    } else {
        std::shared_ptr<ASTNodeTrunk> nodeTrunk = dynamic_pointer_cast<ASTNodeTrunk>(child);
        generate(nodeTrunk, ss);
    }
}
