#ifndef SIMPLECOMPILER_COMPILESTRUCTURE_H
#define SIMPLECOMPILER_COMPILESTRUCTURE_H

#include <functional>
#include <memory>
#include <ostream>

typedef std::function<std::string(int)> type2stringFunc;

namespace LexicalStruct {
    struct Token {
        int type;
        std::string value;

        static type2stringFunc type2string;

        friend std::ostream &operator<<(std::ostream &os, const Token &token);
    };
}
typedef LexicalStruct::Token Token;

namespace SyntacticStruct {
    struct ASTNode {
        int type;
        std::string value;
        bool isLeaf;

        explicit ASTNode(int t, std::string v, bool l) : type(t), value(std::move(v)), isLeaf(l) {}

        static type2stringFunc type2string;

        virtual std::ostream &outputToStream(std::ostream &os) const = 0;
    };

    std::ostream &operator<<(std::ostream &os, const ASTNode *node);


    struct ASTNodeTrunk : public ASTNode {
        std::vector<std::shared_ptr<ASTNode>> children;

        explicit ASTNodeTrunk(int t, std::string v) : ASTNode(t, std::move(v), false) {}

        std::ostream &outputToStream(std::ostream &os) const override;
    };


    struct ASTNodeLeaf : public ASTNode {
        explicit ASTNodeLeaf(int t, std::string v) : ASTNode(t, std::move(v), true) {};

        std::ostream &outputToStream(std::ostream &os) const override;
    };
}
typedef SyntacticStruct::ASTNode ASTNode;
typedef SyntacticStruct::ASTNodeTrunk ASTNodeTrunk;
typedef SyntacticStruct::ASTNodeLeaf ASTNodeLeaf;


#endif //SIMPLECOMPILER_COMPILESTRUCTURE_H
