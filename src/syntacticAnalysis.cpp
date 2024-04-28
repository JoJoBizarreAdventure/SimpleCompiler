#include "syntacticAnalysis.h"

std::shared_ptr<SyntacticAnalysis::ASTNodeTrunk> SyntacticAnalysis::compile(const std::vector<Token> &tokens) {
    std::shared_ptr<ASTNodeTrunk> root = parser(tokens);
#ifdef DEBUG_LOG
    printTree(root);
#endif
    return root;
}

static int tabNum = 0;

void printTab() {
    for (unsigned int i = 0; i < tabNum; i++) {
        std::cout << '-';
    }
}

void SyntacticAnalysis::printTree(const std::shared_ptr<ASTNode> &node) {
    tabNum = 0;
    node->print();
}

void SyntacticAnalysis::ASTNodeTrunk::print() {
    printTab();
    tabNum++;
    std::cout << "type: " << type << std::endl;
    for (const auto &node: children) {
        node->print();
    }
    tabNum--;
}

void SyntacticAnalysis::ASTNodeLeaf::print() {
    printTab();
    std::cout << "type: " << type << "\tvalue: " << value << std::endl;
}
