#pragma once
#include "Entities/Shapes/Shape.h"

namespace Coco2Engine {

    class Square : public Shape {


    private:

    protected:
      virtual  void SetVertexsAndIndex() override;
    public:
        Square(Shader* ShaderToUse);

        virtual void Draw();


    };

}