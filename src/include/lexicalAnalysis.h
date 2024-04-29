#ifndef SIMPLECOMPILER_LEXICALANALYSIS_H
#define SIMPLECOMPILER_LEXICALANALYSIS_H

#include <string>
#include <vector>
#include <iostream>

#include "compileStructure.h"

/*
 *  Breaks the input code (string) into the basic syntax
 *      of the language (array of objects)
 *
 * Implement and override function(tokenizer) with detail
 * */

class LexicalAnalysis {
private:
    virtual std::string int2TokenType(int i);

    void printTokens(const std::vector<Token> &tokens);

public:
    std::vector<Token> compile(const std::string &target);

private:
    virtual void tokenizer(const std::string &target, std::vector<Token> &tokens) = 0;
};

#endif //SIMPLECOMPILER_LEXICALANALYSIS_H
