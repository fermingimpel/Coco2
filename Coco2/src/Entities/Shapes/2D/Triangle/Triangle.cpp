#include "Triangle.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

#include <iostream>

#include "Extras/GameplayStatics.h"
#include "Shader/Shader.h"

namespace Coco2Engine {

	void Triangle::SetVertexsAndIndex() {
		//Pos - Color - Texture Coords
		EntityVertexs = {
			-0.5f, -0.5f, 0.0f, /**/ 1.0f, 1.0f, 1.0f, /**/	0.0f, 0.0f,  // lower-left corner  
			 0.5f, -0.5f, 0.0f,	/**/ 1.0f, 1.0f, 1.0f, /**/ 1.0f, 0.0f,  // lower-right corner
			 0.0f,  0.5f, 0.0f,	/**/ 1.0f, 1.0f, 1.0f, /**/ 0.5f, 1.0f   // top-center corner
		};
	}

	Triangle::Triangle() : Shape() {
		SetVertexsAndIndex();
		BindBuffers();
		BindIndexs();
	}

	void Triangle::Draw() {
		glUseProgram(GetMainShader()->GetShader());
		glBindVertexArray(VertexArrayObject);

		glEnable(GL_DEPTH_TEST);

		UpdateMVP();
		glUniform1i(UniformUseTexture, HasTextureLoaded);

		if (HasTextureLoaded) {
			EntityTexture->StartUsingTexture();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			EntityTexture->StopUsingTexture();
		}
		else {
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		
		glUseProgram(0);
		glBindVertexArray(0);
	}

}