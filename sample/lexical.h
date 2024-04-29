#ifndef SIMPLECOMPILER_LEXICAL_H
#define SIMPLECOMPILER_LEXICAL_H

#include "lexicalAnalysis.h"
#include " enum2stringSupport.h"

class Lexical : public LexicalAnalysis, private Enum2stringSupport<Token> {
public:
    enum TokenType : int {
        Parenthesis = 0,
        Name,
        Number
    };

    Lexical();

private:
    void tokenizer(const std::string &target, std::vector<Token> &tokens) override;
};


#endif //SIMPLECOMPILER_LEXICAL_H
