#include "lexical.h"

#include <iostream>

const std::string Enum2Str [] {
        "Parenthesis",
        "Name       ",
        "Number     "
};

Lexical::Lexical(const std::string &target) : LexicalAnalysis(target, [](int i) {
    return Enum2Str[i];
}) {}

void Lexical::tokenizer(const std::string &target, std::vector<Token> &tokens) {
    for (int i = 0; i < target.size();) {
        const auto &c = target[i];
        if (std::isspace(c)) {
            i++;
        } else if (c == '(' || c == ')') {
            tokens.emplace_back(Parenthesis, std::string(1, c));
            i++;
        } else if (std::isdigit(c)) {
            std::string value(1, c);
            i++;
            while (i < target.size() && std::isalpha(target[i])) {
                value.push_back(target[i]);
                i++;
            }
            tokens.emplace_back(Number, value);
        } else if (std::isalpha(c)) {
            std::string value(1, c);
            i++;
            while (i < target.size() && std::isalpha(target[i])) {
                value.push_back(target[i]);
                i++;
            }
            tokens.emplace_back(Name, value);
        } else {
            std::cerr << "Unexpected character: " << c << std::endl;
            std::abort();
        }
    }
}

