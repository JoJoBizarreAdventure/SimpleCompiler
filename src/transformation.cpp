#include "transformation.h"

#include <iostream>

std::shared_ptr<ASTNodeTrunk> Transformation::compile(const std::shared_ptr<ASTNodeTrunk> &root) {
    auto newRoot = transformer(root);
#ifdef DEBUG_LOG
    std::cout << "Transformed AST Tree:" << std::endl << root << std::endl << std::endl;
#endif
    return newRoot;
}