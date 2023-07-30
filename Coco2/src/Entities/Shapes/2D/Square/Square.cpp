#include "Square.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

namespace Coco2Engine {

	float SquareVertexs[] = {
		0.5f,  0.5f, 0.0f, 
	 0.5f, -0.5f, 0.0f, 
	-0.5f, -0.5f, 0.0f, 
	-0.5f,  0.5f, 0.0f  
	};
	
	unsigned int indices[] = {  
	0, 1, 3,  
	1, 2, 3   
	};


	Square::Square(Shader* ShaderToUse) : Shape(ShaderToUse) {
		glGenVertexArrays(1, &VertexArrayObject);
		glGenBuffers(1, &VertexBufferObject);
		glBindVertexArray(VertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(SquareVertexs), SquareVertexs, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glGenBuffers(1, &ElementBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Square::Draw() {

		glUseProgram(EntityShader->GetShader());
		glBindVertexArray(VertexArrayObject);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glUseProgram(0);
		glBindVertexArray(0);

	}

}