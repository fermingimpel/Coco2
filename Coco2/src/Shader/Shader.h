#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <string>

namespace Coco2Engine {

	class Shader {

	private:
		unsigned int ShaderID;

		void CompileShader(const char* vertexCode, const char* fragmentCode);
		void AddShader(unsigned int program, const char* shaderCode, unsigned int type);
		std::string ReadFile(const char* location);
	public:
		Shader();
		~Shader();
		void CreateFromLocation(const char* vertexLocation, const char* fragmentLocation);
		void ClearShader();
		unsigned int GetShader();

	};

}

#endif