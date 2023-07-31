#include "Triangle.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

#include <iostream>

namespace Coco2Engine {

	void Triangle::SetVertexsAndIndex() {
		EntityVertexs = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
	}

	Triangle::Triangle(Shader* ShaderToUse) : Shape(ShaderToUse) {
		SetVertexsAndIndex();
		BindBuffers();
		BindIndexs();
	}

	void Triangle::Draw() {
		glUseProgram(EntityShader->GetShader());
		glBindVertexArray(VertexArrayObject);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(0);
		glBindVertexArray(0);

	}

}