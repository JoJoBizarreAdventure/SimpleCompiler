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

    Lexical();

    ~Lexical();

private:
    void tokenizer(const std::string &target, std::vector<Token> &tokens) override;

public:
    static std::string tokenTypeStr(int i);
};


#endif //SIMPLECOMPILER_LEXICAL_H
