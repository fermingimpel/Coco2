#ifndef SQUARE_H
#define SQUARE_H

#include "Entities/Shapes/Shape.h"

namespace Coco2Engine {

    class Square : public Shape {


    private:

    protected:
      virtual  void SetVertexsAndIndex() override;
    public:
        Square();

        virtual void Draw();


    };

}

#endif