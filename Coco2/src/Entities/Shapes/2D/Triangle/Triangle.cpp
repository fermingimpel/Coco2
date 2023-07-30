#include "Triangle.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

#include <iostream>

namespace Coco2Engine {

	float Vertexs[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
	};

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";


	Triangle::Triangle() : Shape() {

		VertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(VertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(VertexShader);

		int  success;
		char infoLog[512];
		glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &success);


		if (!success) {
			glGetShaderInfoLog(VertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(FragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(FragmentShader);

		glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(FragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		ShaderProgram = glCreateProgram();
		glAttachShader(ShaderProgram, VertexShader);
		glAttachShader(ShaderProgram, FragmentShader);
		glLinkProgram(ShaderProgram);

		glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(ShaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR LINKIN SHADERS PROGRAM" << infoLog << std::endl;
		}

		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);

		glGenVertexArrays(1, &VertexArrayObject);
		glGenBuffers(1, &VertexBufferObject);
		glBindVertexArray(VertexArrayObject);
		
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertexs), Vertexs, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Triangle::Draw() {
		glUseProgram(ShaderProgram);
		glBindVertexArray(VertexArrayObject);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(0);
		glBindVertexArray(0);

	}

}