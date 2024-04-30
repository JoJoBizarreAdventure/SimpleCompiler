#ifndef SIMPLECOMPILER_GENERATION_H
#define SIMPLECOMPILER_GENERATION_H

#include "codeGeneration.h"

class Generation : public CodeGeneration {
private:
    std::string generateCode(const std::shared_ptr<ASTNodeTrunk> &root) override;

    static void generate(const std::shared_ptr<ASTNodeTrunk> &node, std::stringstream &ss);

    static void generate(const std::shared_ptr<ASTNodeLeaf> &node, std::stringstream &ss);

    static void generateChild(const std::shared_ptr<ASTNode> &child, std::stringstream &ss);
};


#endif //SIMPLECOMPILER_GENERATION_H
