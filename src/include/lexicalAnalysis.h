#ifndef SIMPLECOMPILER_LEXICALANALYSIS_H
#define SIMPLECOMPILER_LEXICALANALYSIS_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>

class LexicalAnalysis {
private:
    std::string target;
public:
    explicit LexicalAnalysis(std::string target);

    explicit LexicalAnalysis(std::string target, std::function<std::string(int)> func);

protected:
    struct Token {
        int type;
        std::string value;
    };
private:
    std::function<std::string(int)> int2EnumStr;

    void printTokens(const std::vector<Token> &tokens);

public:
    void compile();

private:
    virtual void tokenizer(const std::string &target, std::vector<Token> &tokens) = 0;
};

#endif //SIMPLECOMPILER_LEXICALANALYSIS_H
