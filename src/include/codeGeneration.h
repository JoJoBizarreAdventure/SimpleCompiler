#ifndef SIMPLECOMPILER_CODEGENERATION_H
#define SIMPLECOMPILER_CODEGENERATION_H

#include <string>
#include <memory>

#include "compileStructure.h"

/*
 *  Transforms our target AST (object of objects)
 *      into actual code (string)
 * */

class CodeGeneration {
public:
    std::string compile(const std::shared_ptr<ASTNodeTrunk> &root);
private:
    virtual std::string generateCode(const std::shared_ptr<ASTNodeTrunk> &root) = 0;
};


#endif //SIMPLECOMPILER_CODEGENERATION_H
