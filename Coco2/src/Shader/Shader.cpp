#include "Shader.h"

#include <glew/glew.h>

#include <iostream>

namespace Coco2Engine {

	Shader::Shader() {
		ShaderID = 0;
	}

	Shader::~Shader() {

	}
	void Shader::CompileShader(const char* vertexCode, const char* fragmentCode) {
		ShaderID = glCreateProgram();
		if (!ShaderID) {
			std::cout << "Error creating the shader program!" << std::endl;
			return;
		}

		AddShader(ShaderID, vertexCode, GL_VERTEX_SHADER);
		AddShader(ShaderID, fragmentCode, GL_FRAGMENT_SHADER);

		int result = 0;
		char eLog[1024] = { 0 };

		glLinkProgram(ShaderID);

		glGetProgramiv(ShaderID, GL_LINK_STATUS, &result);

		if (!result) {
			glGetProgramInfoLog(ShaderID, sizeof(eLog), NULL, eLog);
			std::cout << "Error linking program: " << eLog << std::endl;
			return;
		}

		glValidateProgram(ShaderID);
		glGetProgramiv(ShaderID, GL_VALIDATE_STATUS, &result);
		if (!result) {
			glGetProgramInfoLog(ShaderID, sizeof(eLog), NULL, eLog);
			std::cout << "Error validating program: " << eLog << std::endl;
			return;
		}

	}

	void Shader::AddShader(unsigned int program, const char* shaderCode, unsigned int type) {
		unsigned int theShader = glCreateShader(type);

		const char* code[1];
		code[0] = shaderCode;

		int codeLength[1];
		codeLength[0] = strlen(shaderCode);

		glShaderSource(theShader, 1, code, codeLength);

		glCompileShader(theShader);

		int result = 0;
		char eLog[1024] = { 0 };

		glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);

		if (!result) {
			glGetProgramInfoLog(theShader, sizeof(eLog), NULL, eLog);
			std::cout << "Error compiling the " << type << " program: " << eLog << std::endl;
			return;
		}
		glAttachShader(program, theShader);
	}

	std::string Shader::ReadFile(const char* location) {
		std::string content;
		std::ifstream fileStream(location, std::ios::in);

		if (!fileStream.is_open()) {
			std::cout << "Failed to read the file: " << location << std::endl;
			return "";
		}

		std::string line = "";
		while (!fileStream.eof()) {
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;
	}

	void Shader::CreateFromLocation(const char* vertexLocation, const char* fragmentLocation) {
		std::string vertexString = ReadFile(vertexLocation);
		std::string fragmentString = ReadFile(fragmentLocation);

		const char* vertexCode = vertexString.c_str();
		const char* fragmentCode = fragmentString.c_str();

		CompileShader(vertexCode, fragmentCode);
	}

	void Shader::ClearShader() {
		if (ShaderID != 0) {
			glDeleteProgram(ShaderID);
			ShaderID = 0;
		}
	}
	unsigned int Shader::GetShader() {
		return ShaderID;
	}

}