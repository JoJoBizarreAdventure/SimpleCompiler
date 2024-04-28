#ifndef SIMPLECOMPILER_LEXICALANALYSIS_H
#define SIMPLECOMPILER_LEXICALANALYSIS_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>

/*
 *  Breaks the input code (string) into the basic syntax
 *      of the language (array of objects)
 *
 * Implement and override function(tokenizer) with detail
 * */

class LexicalAnalysis {
private:
    std::string target;
public:
    explicit LexicalAnalysis(std::string target);

    explicit LexicalAnalysis(std::string target, std::function<std::string(int)> func);

    struct Token {
        int type;
        std::string value;
    };
private:
    std::function<std::string(int)> int2EnumStr;

    void printTokens(const std::vector<Token> &tokens);

public:
    std::vector<Token> compile();

private:
    virtual void tokenizer(const std::string &target, std::vector<Token> &tokens) = 0;
};

#endif //SIMPLECOMPILER_LEXICALANALYSIS_H
