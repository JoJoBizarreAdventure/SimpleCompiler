#ifndef SIMPLECOMPILER_SYNTACTIC_H
#define SIMPLECOMPILER_SYNTACTIC_H

#include "syntacticAnalysis.h"
#include " enum2stringSupport.h"

class Syntactic : public SyntacticAnalysis, private Enum2stringSupport<ASTNode> {
public:
    enum SyntacticType {
        Program = 0,
        NumberLiteral,
        CallExpression
    };

    Syntactic();

private:
    std::shared_ptr<ASTNodeTrunk> parser(const std::vector<Token> &tokens) override;

    int tokenPtr = 0;

    void walk(const std::vector<Token> &tokens, const std::shared_ptr<ASTNodeTrunk> &node);


};


#endif //SIMPLECOMPILER_SYNTACTIC_H
