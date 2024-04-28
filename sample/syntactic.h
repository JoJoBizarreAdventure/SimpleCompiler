#ifndef SIMPLECOMPILER_SYNTACTIC_H
#define SIMPLECOMPILER_SYNTACTIC_H

#include "syntacticAnalysis.h"

class Syntactic : public SyntacticAnalysis {
private:
    std::shared_ptr<ASTNodeTrunk> parser(const std::vector<Token> &tokens) override;

    enum SyntacticType {
        Program = 0,
        NumberLiteral,
        CallExpression
    };

    int tokenPtr = 0;

    void walk(const std::vector<Token> &tokens, const std::shared_ptr<ASTNodeTrunk> &node);

    std::string int2SyntacticType(int i) override;
};


#endif //SIMPLECOMPILER_SYNTACTIC_H
