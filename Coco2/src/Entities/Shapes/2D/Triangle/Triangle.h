#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "Entities/Shapes/Shape.h"

namespace Coco2Engine {

	class Triangle : public Shape {

	private:

	protected:

		virtual void SetVertexsAndIndex() override;

	public:
		Triangle();

		virtual void Draw() override;
	};


}

#endif