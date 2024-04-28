#ifndef SIMPLECOMPILER_LEXICAL_H
#define SIMPLECOMPILER_LEXICAL_H

#include "lexicalAnalysis.h"

class Lexical : public LexicalAnalysis {
public:
    Lexical();

private:
    enum TokenType : int {
        Parenthesis = 0,
        Name,
        Number
    };

    void tokenizer(const std::string &target, std::vector<Token> &tokens) override;
};


#endif //SIMPLECOMPILER_LEXICAL_H
