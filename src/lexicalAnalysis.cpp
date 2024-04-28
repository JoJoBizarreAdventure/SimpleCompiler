#include "lexicalAnalysis.h"

#include <utility>

LexicalAnalysis::LexicalAnalysis(std::string target) :
        target(std::move(target)),
        int2EnumStr([](int i) -> std::string {
            return std::to_string(i);
        }) {}

LexicalAnalysis::LexicalAnalysis(std::string target, std::function<std::string(int)> func) :
        target(std::move(target)),
        int2EnumStr(std::move(func)) {}

std::vector<LexicalAnalysis::Token> LexicalAnalysis::compile() {
    std::vector<Token> tokens;
    tokenizer(target, tokens);
#ifdef DEBUG_LOG
    printTokens(tokens);
#endif
    return tokens;
}

void LexicalAnalysis::printTokens(const std::vector<Token> &tokens) {
    std::cout << "tokens:" << std::endl;
    for (const auto &token: tokens) {
        std::cout << "  type: " << int2EnumStr(token.type) << "\tvalue:" << token.value << std::endl;
    }
    std::cout << std::endl << std::endl;
}
