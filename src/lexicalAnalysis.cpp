#include "lexicalAnalysis.h"

std::vector<LexicalAnalysis::Token> LexicalAnalysis::compile(const std::string &target) {
    std::vector<Token> tokens;
    tokenizer(target, tokens);
#ifdef DEBUG_LOG
    printTokens(tokens);
#endif
    return tokens;
}

std::string LexicalAnalysis::int2TokenType(int i) {
    return std::to_string(i);
}


void LexicalAnalysis::printTokens(const std::vector<Token> &tokens) {
    std::cout << "tokens:" << std::endl;
    for (const auto &token: tokens) {
        std::cout << "  type: " << int2TokenType(token.type) << "\tvalue:" << token.value << std::endl;
    }
    std::cout << std::endl << std::endl;
}
