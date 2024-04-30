#include "codeGeneration.h"

#include <iostream>

std::string CodeGeneration::compile(const std::shared_ptr<ASTNodeTrunk> &root) {
    auto result = generateCode(root);
#ifdef DEBUG_LOG
    std::cout << "Final Code:" << std::endl << result << std::endl;
#endif
    return result;
}
