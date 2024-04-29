#ifndef SIMPLECOMPILER_TRANSFORM_H
#define SIMPLECOMPILER_TRANSFORM_H

#include "transformation.h"
#include " enum2stringSupport.h"

class Transform : public Transformation, private Enum2stringSupport<ASTNode> {
public:
    enum TransformType {
        LuaProgram = 0,
        LuaInt,
        LuaMathOp
    };

    Transform();

private:
    std::shared_ptr<ASTNodeTrunk> transformer(const std::shared_ptr<ASTNodeTrunk> &root) override;

    static ASTNodeTrunk *travel(const std::shared_ptr<ASTNodeTrunk> &oldNode);

    static ASTNodeLeaf *travel(const std::shared_ptr<ASTNodeLeaf> &oldNode);
};


#endif //SIMPLECOMPILER_TRANSFORM_H
