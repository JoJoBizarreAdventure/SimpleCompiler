#ifndef SIMPLECOMPILER_COMPILESTRUCTURE_H
#define SIMPLECOMPILER_COMPILESTRUCTURE_H

#include <functional>
#include <memory>

namespace LexicalStruct {
    struct Token {
        int type;
        std::string value;

        static std::function<std::string(int)>type2string;
    };
}
typedef LexicalStruct::Token Token;
void printToken(const Token& token);

namespace SyntacticStruct {
    struct ASTNode {
        int type;
        std::string value;
        bool isLeaf;

        explicit ASTNode(int t, std::string v, bool l) : type(t), value(std::move(v)), isLeaf(l) {}

        virtual void print(const std::function<std::string(int)> &queryStr) = 0;
    };

    struct ASTNodeTrunk : public ASTNode {
        std::vector<std::shared_ptr<ASTNode>> children;

        explicit ASTNodeTrunk(int t, std::string v) : ASTNode(t, std::move(v), false) {}

        void print(const std::function<std::string(int)> &queryStr) override;
    };


    struct ASTNodeLeaf : public ASTNode {
        explicit ASTNodeLeaf(int t, std::string v) : ASTNode(t, std::move(v), true) {};

        void print(const std::function<std::string(int)> &queryStr) override;
    };
}
typedef SyntacticStruct::ASTNode ASTNode;
typedef SyntacticStruct::ASTNodeTrunk ASTNodeTrunk;
typedef SyntacticStruct::ASTNodeLeaf ASTNodeLeaf;

#endif //SIMPLECOMPILER_COMPILESTRUCTURE_H
