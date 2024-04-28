#ifndef SIMPLECOMPILER_LEXICAL_H
#define SIMPLECOMPILER_LEXICAL_H

#include "lexicalAnalysis.h"

class Lexical : public LexicalAnalysis {
public:
    enum TokenType : int {
        Parenthesis = 0,
        Name,
        Number
    };

private:
    void tokenizer(const std::string &target, std::vector<Token> &tokens) override;

public:
    static std::string tokenTypeStr(int i);

private:
    std::string int2TokenType(int i) override;
};


#endif //SIMPLECOMPILER_LEXICAL_H
