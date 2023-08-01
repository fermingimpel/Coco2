#include "Square.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

namespace Coco2Engine {


	void Square::SetVertexsAndIndex() {
		EntityVertexs = {
			// positions          // colors           // texture coords
				0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
				0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
			   -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
			   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
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

		if (HasTextureLoaded) {
			EntityTexture->StartUsingTexture();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			EntityTexture->StopUsingTexture();
		}
		else {
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

		glUseProgram(0);
		glBindVertexArray(0);

	}

}