#include "compileStructure.h"

#include <iostream>

static int tabNum = 0;

void printTab() {
    for (unsigned int i = 0; i < tabNum; i++) {
        std::cout << '\t';
    }
}

void ASTNodeTrunk::print(const std::function<std::string(int)> &queryStr) {
    printTab();
    tabNum++;
    std::cout << "type: " << queryStr(type);
    if (!value.empty()) {
        std::cout << "  value: " << value;
    }
    std::cout << "  children: [" << std::endl;
    for (const auto &node: children) {
        node->print(queryStr);
    }
    tabNum--;
    printTab();
    std::cout << "]" << std::endl;
}

void ASTNodeLeaf::print(const std::function<std::string(int)> &queryStr) {
    printTab();
    std::cout << "type: " << queryStr(type) << "    value: " << value << std::endl;
}