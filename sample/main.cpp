#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "lexical.h"
#include "syntactic.h"
#include "transform.h"
#include "generation.h"

int parseArgs(int argc, char *argv[], std::string &path) {
    if (argc == 1) {
        path = "input/test.txt";
        std::cout << "Init: using default input file: input/test.txt" << std::endl;
    } else if (argc == 2) {
        path = argv[1];
        std::cout << "Init: using args input file: " << path << std::endl;
    } else {
        std::cerr << "Init: please input only 1 args (or not)";
        return -1;
    }
    return 0;
}

int loadFile(const std::string &path, std::string &content) {
    std::ifstream inFileStream(path);
    if (!(inFileStream.good() && inFileStream.is_open())) {
        std::cerr << "Load File: can't open file - " << path << std::endl;
        inFileStream.close();
        return -2;
    }

    std::stringstream ss;
    ss << inFileStream.rdbuf();
    inFileStream.close();
    content = ss.str();
    std::cout << "Load File: content as below\n" << content << std::endl << std::endl;

    return 0;
}



int main(int argc, char *argv[]) {
    std::string inputFile;
    if (parseArgs(argc, argv, inputFile)) {
        return -1;
    }

    std::string inputContent;
    if (loadFile(inputFile, inputContent)) {
        return -2;
    }

    std::vector<Token> tokens;
    {
        Lexical lexical;
        tokens = lexical.compile(inputContent);
    }

    std::shared_ptr<ASTNodeTrunk> tree;
    {
        Syntactic syntactic;
        tree = syntactic.compile(tokens);
    }

    std::shared_ptr<ASTNodeTrunk> newTree;
    {
        Transform transform;
        newTree = transform.compile(tree);
    }

    std::string outputContent;
    {
        Generation generation;
        outputContent = generation.compile(newTree);
    }

    return 0;
}