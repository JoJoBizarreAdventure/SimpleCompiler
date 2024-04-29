#ifndef SIMPLECOMPILER_SYNTACTIC_H
#define SIMPLECOMPILER_SYNTACTIC_H

#include "syntacticAnalysis.h"

class Syntactic : public SyntacticAnalysis {
private:
    std::shared_ptr<ASTNodeTrunk> parser(const std::vector<Token> &tokens) override;

    int tokenPtr = 0;

    void walk(const std::vector<Token> &tokens, const std::shared_ptr<ASTNodeTrunk> &node);
public:
    enum SyntacticType {
        Program = 0,
        NumberLiteral,
        CallExpression
    };

    Syntactic();
    ~Syntactic();
};


#endif //SIMPLECOMPILER_SYNTACTIC_H
