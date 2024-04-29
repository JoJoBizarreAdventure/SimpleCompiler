#include "syntacticAnalysis.h"

#include <iostream>

std::shared_ptr<ASTNodeTrunk> SyntacticAnalysis::compile(const std::vector<Token> &tokens) {
    std::shared_ptr<ASTNodeTrunk> root = parser(tokens);
#ifdef DEBUG_LOG
    std::cout << "AST Tree:" << std::endl;
    printTree(root);
    std::cout << std::endl;
#endif
    return root;
}

void SyntacticAnalysis::printTree(const std::shared_ptr<ASTNodeTrunk> &node) {
    node->print();
}
