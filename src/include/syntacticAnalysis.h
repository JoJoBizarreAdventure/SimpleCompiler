#ifndef SIMPLECOMPILER_SYNTACTICANALYSIS_H
#define SIMPLECOMPILER_SYNTACTICANALYSIS_H

#include <memory>
#include <utility>

#include "lexicalAnalysis.h"

/*
 *  Transforms the tokens (array of objects) into an
 *      AST (tree of objects) which represents our program
 *
 * */

class SyntacticAnalysis {
public:
    struct ASTNode {
        int type;
        std::string value;

        explicit ASTNode(int t, std::string v) : type(t), value(std::move(v)) {}

        virtual void print() = 0;
    };

    struct ASTNodeTrunk : public ASTNode {
        std::vector<std::shared_ptr<ASTNode>> children;

        explicit ASTNodeTrunk(int t, std::string v) : ASTNode(t, std::move(v)) {}

        void print() override;
    };

    struct ASTNodeLeaf : public ASTNode {

        explicit ASTNodeLeaf(int t, std::string v) : ASTNode(t, std::move(v)) {};

        void print() override;
    };

protected:
    typedef LexicalAnalysis::Token Token;
private:
    virtual std::shared_ptr<ASTNodeTrunk> parser(const std::vector<Token> &tokens) = 0;

public:
    std::shared_ptr<ASTNodeTrunk> compile(const std::vector<Token> &tokens);

private:
    static void printTree(const std::shared_ptr<ASTNode> &node);
};

#endif //SIMPLECOMPILER_SYNTACTICANALYSIS_H
