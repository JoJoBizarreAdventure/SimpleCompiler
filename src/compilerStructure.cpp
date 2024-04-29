#include "compileStructure.h"

#include <iostream>

#pragma region Lexical Token

std::function<std::string(int)> LexicalStruct::Token::type2string = nullptr;

void printToken(const Token &token) {
    std::cout << "type: ";
    if (Token::type2string) {
        std::cout << Token::type2string(token.type);
    } else {
        std::cout << token.type;
    }
    std::cout << "\tvalue:" << token.value;
}

#pragma endregion

#pragma region Syntactic Node

std::function<std::string(int)> SyntacticStruct::ASTNode::type2string = nullptr;

static int tabNum = 0;

void printTab() {
    for (unsigned int i = 0; i < tabNum; i++) {
        std::cout << '\t';
    }
}

void ASTNodeTrunk::print() {
    printTab();
    tabNum++;
    std::cout << "type: ";
    if (type2string)
        std::cout << type2string(type);
    else
        std::cout << type;
    if (!value.empty()) {
        std::cout << "  value: " << value;
    }
    std::cout << "  children: [" << std::endl;
    for (const auto &node: children) {
        node->print();
    }
    tabNum--;
    printTab();
    std::cout << "]" << std::endl;
}

void ASTNodeLeaf::print() {
    printTab();
    std::cout << "type: ";
    if (type2string)
        std::cout << type2string(type);
    else
        std::cout << type;
    std::cout << "    value: " << value << std::endl;
}

#pragma endregion