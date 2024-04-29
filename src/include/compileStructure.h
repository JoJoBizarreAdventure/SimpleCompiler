#ifndef SIMPLECOMPILER_COMPILESTRUCTURE_H
#define SIMPLECOMPILER_COMPILESTRUCTURE_H

#include <functional>
#include <memory>

namespace LexicalStruct{
    struct Token {
        int type;
        std::string value;
    };
}
typedef LexicalStruct::Token Token;

namespace SyntacticStruct{
    struct ASTNode {
        int type;
        std::string value;

        explicit ASTNode(int t, std::string v) : type(t), value(std::move(v)) {}

        virtual void print(const std::function<std::string(int)> &queryStr) = 0;
    };

    struct ASTNodeTrunk : public ASTNode {
        std::vector<std::shared_ptr<ASTNode>> children;

        explicit ASTNodeTrunk(int t, std::string v) : ASTNode(t, std::move(v)) {}

        void print(const std::function<std::string(int)> &queryStr) override;
    };



    struct ASTNodeLeaf : public ASTNode {
        explicit ASTNodeLeaf(int t, std::string v) : ASTNode(t, std::move(v)) {};

        void print(const std::function<std::string(int)> &queryStr) override;
    };
}
typedef SyntacticStruct::ASTNode ASTNode;
typedef SyntacticStruct::ASTNodeTrunk ASTNodeTrunk;
typedef SyntacticStruct::ASTNodeLeaf ASTNodeLeaf;

#endif //SIMPLECOMPILER_COMPILESTRUCTURE_H
