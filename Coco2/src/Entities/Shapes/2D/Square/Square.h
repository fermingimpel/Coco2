#pragma once
#include "Entities/Shapes/Shape.h"

namespace Coco2Engine {

    class Square : public Shape {


    private:

    protected:

    public:
        Square(Shader* ShaderToUse);

        virtual void Draw() override;


    };

}