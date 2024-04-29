#ifndef SIMPLECOMPILER_SYNTACTICANALYSIS_H
#define SIMPLECOMPILER_SYNTACTICANALYSIS_H

#include <memory>
#include <utility>
#include <functional>

#include "compileStructure.h"

/*
 *  Transforms the tokens (array of objects) into an
 *      AST (tree of objects) which represents our program
 *
 *  Implement and override function(parser) with detail
 * */

class SyntacticAnalysis {
private:
    virtual std::shared_ptr<ASTNodeTrunk> parser(const std::vector<Token> &tokens) = 0;

public:
    std::shared_ptr<ASTNodeTrunk> compile(const std::vector<Token> &tokens);

private:
    virtual std::string int2SyntacticType(int i);

    void printTree(const std::shared_ptr<ASTNodeTrunk> &node);
};

#endif //SIMPLECOMPILER_SYNTACTICANALYSIS_H
