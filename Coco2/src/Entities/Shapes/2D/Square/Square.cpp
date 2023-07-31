#include "Square.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

namespace Coco2Engine {


	void Square::SetVertexsAndIndex() {
		EntityVertexs = {
	0.5f,  0.5f, 0.0f,
 0.5f, -0.5f, 0.0f,
-0.5f, -0.5f, 0.0f,
-0.5f,  0.5f, 0.0f
		};

		EntityIndexs = {
		0, 1, 3,
		1, 2, 3
		};
	}

	Square::Square(Shader* ShaderToUse) : Shape(ShaderToUse) {
		SetVertexsAndIndex();
		BindBuffers();
		BindIndexs();
	}

	void Square::Draw() {

		glUseProgram(EntityShader->GetShader());
		glBindVertexArray(VertexArrayObject);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glUseProgram(0);
		glBindVertexArray(0);

	}

}