#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char *argv[]) {
    std::string inputFile;
    if (argc == 1) {
        inputFile = "input/test.txt";
        std::cout << "Init: using default input file: input/test.txt" << std::endl;
    } else if (argc == 2) {
        inputFile = argv[1];
        std::cout << "Init: using args input file: " << inputFile << std::endl;
    } else {
        std::cerr << "Init: please input only 1 args (or not)";
        return -1;
    }

    std::ifstream inFileStream(inputFile);
    if (!(inFileStream.good() && inFileStream.is_open())) {
        std::cerr << "Load File: can't open file - " << inputFile << std::endl;
        inFileStream.close();
        return -2;
    }

    std::stringstream stringStream;
    std::string loadBuffer;
    while (!inFileStream.eof()) {
        getline(inFileStream, loadBuffer);
        stringStream << loadBuffer;
    }
    inFileStream.close();
    std::cout << "Load File: content as below\n" << stringStream.str() << std::endl;

    return 0;
}