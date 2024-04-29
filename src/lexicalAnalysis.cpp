#include "lexicalAnalysis.h"

std::vector<Token> LexicalAnalysis::compile(const std::string &target) {
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
        std::cout << "  " << token << std::endl;
    }
    std::cout << std::endl << std::endl;
}
