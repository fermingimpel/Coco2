#pragma once
#include "Entities/Shapes/Shape.h"

namespace Coco2Engine {

	class Triangle : public Shape {

	private:

	protected:



	public:
		Triangle(Shader* ShaderToUse);

		virtual void Draw() override;
	};


}