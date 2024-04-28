#include "syntacticAnalysis.h"

std::shared_ptr<SyntacticAnalysis::ASTNodeTrunk> SyntacticAnalysis::compile(const std::vector<Token> &tokens) {
    std::shared_ptr<ASTNodeTrunk> root = parser(tokens);
#ifdef DEBUG_LOG
    std::cout<<"AST Tree:"<<std::endl;
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
    node->print([this](int i) { return int2SyntacticType(i); });
}

std::string SyntacticAnalysis::int2SyntacticType(int i) {
    return std::to_string(i);
}

void SyntacticAnalysis::ASTNodeTrunk::print(const std::function<std::string(int)> &queryStr) {
    printTab();
    tabNum++;
    std::cout << "type: " << queryStr(type);
    if(!value.empty()){
        std::cout<<"    value: "<<value;
    }
    std::cout<< std::endl;
    for (const auto &node: children) {
        node->print(queryStr);
    }
    tabNum--;
}

void SyntacticAnalysis::ASTNodeLeaf::print(const std::function<std::string(int)> &queryStr) {
    printTab();
    std::cout << "type: " << queryStr(type) << "    value: " << value << std::endl;
}
