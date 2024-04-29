#include "compileStructure.h"

#include <iostream>

#pragma region Lexical Token

std::function<std::string(int)> LexicalStruct::Token::type2string = nullptr;

std::ostream &LexicalStruct::operator<<(std::ostream &os, const Token &token) {
    os << "type: ";
    if (Token::type2string) {
        os << Token::type2string(token.type);
    } else {
        os << token.type;
    }
    os << "\tvalue:" << token.value;
    return os;
}

#pragma endregion

#pragma region Syntactic Node

std::ostream &SyntacticStruct::operator<<(std::ostream &os, const ASTNode *node) {
    node->outputToStream(os);
    return os;
}

std::function<std::string(int)> SyntacticStruct::ASTNode::type2string = nullptr;

static int tabNum = 0;

void printTab(std::ostream &os) {
    for (unsigned int i = 0; i < tabNum; i++) {
        os << '\t';
    }
}

std::ostream &SyntacticStruct::ASTNodeTrunk::outputToStream(std::ostream &os) const {
    printTab(os);
    tabNum++;
    os << "type: ";
    if (ASTNode::type2string)
        os << ASTNode::type2string(type);
    else
        os << type;
    if (!value.empty()) {
        os << "  value: " << value;
    }
    os << "  children: [" << std::endl;
    for (const auto &child: children) {
        os << child << std::endl;
    }
    tabNum--;
    printTab(os);
    os << "]";
    return os;
}

std::ostream &SyntacticStruct::ASTNodeLeaf::outputToStream(std::ostream &os) const {
    printTab(os);
    os << "type: ";
    if (ASTNode::type2string)
        os << ASTNode::type2string(type);
    else
        os << type;
    std::cout << "    value: " << value;
    return os;
}

#pragma endregion


