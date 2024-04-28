#include "syntactic.h"
#include "lexical.h"

std::shared_ptr<SyntacticAnalysis::ASTNodeTrunk> Syntactic::parser(const std::vector<Token> &tokens) {
    auto root = std::make_shared<ASTNodeTrunk>(Program, "");
    tokenPtr = 0;
    walk(tokens, root);
    return root;
}

void Syntactic::walk(const std::vector<Token> &tokens, const std::shared_ptr<ASTNodeTrunk> &node) {
    if (tokenPtr >= tokens.size()) {
        std::cerr << "Syntactic Analysis: tokenPtr indexOutOfBound unexpectedly" << std::endl;
        std::abort();
    }

    auto &token = tokens[tokenPtr];

    if (token.type == Lexical::TokenType::Number) {
        tokenPtr++;
        node->children.push_back(std::make_shared<ASTNodeLeaf>(NumberLiteral, token.value));
    } else if (token.type == Lexical::TokenType::Parenthesis && token.value == "(") {
        tokenPtr++;
        if (tokens[tokenPtr].type != Lexical::TokenType::Name) {
            std::cerr << "Syntactic Analysis: expected a name after ( - type:" << tokens[tokenPtr].type
                      << "\tvalue: " << tokens[tokenPtr].value << std::endl;
            std::abort();
        }
        auto expression = std::make_shared<ASTNodeTrunk>(CallExpression, tokens[tokenPtr].value);
        tokenPtr++;
        while (tokens[tokenPtr].value != ")") {
            walk(tokens, expression);
        }
        tokenPtr++;
        node->children.push_back(expression);
    } else {
        std::cerr << "Syntactic Analysis: unexpected token - type:" << token.type << "\tvalue: " << token.value
                  << std::endl;
        std::abort();
    }
}
