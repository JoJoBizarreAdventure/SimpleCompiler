#ifndef SIMPLECOMPILER_TRANSFORMATION_H
#define SIMPLECOMPILER_TRANSFORMATION_H

#include <memory>
#include "compileStructure.h"

/*
 * Transforms our original Lisp AST into
 * our target Javascript AST
 * */

class Transformation {
public:
    std::shared_ptr<ASTNodeTrunk> compile(const std::shared_ptr<ASTNodeTrunk> &root);

private:
    virtual std::shared_ptr<ASTNodeTrunk> transformer(const std::shared_ptr<ASTNodeTrunk> &root) = 0;
};


#endif //SIMPLECOMPILER_TRANSFORMATION_H
