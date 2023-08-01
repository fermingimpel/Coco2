#include "Texture.h"

#include <glew/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

namespace Coco2Engine {

	Texture::Texture() {
	}

	Texture::~Texture() {
		UnloadTexture();
	}

	bool Texture::LoadTexture(const std::string Path, const std::string Name) {
		stbi_set_flip_vertically_on_load(true);
	
		std::string pathName = Path + "/" + Name;
		TextureData = stbi_load(pathName.c_str(), &TextureWidth, &TextureHeight, &TextureChannels, 0);

		if (!TextureData) {
			std::cout << "Cant Load Texture: " << Name << std::endl;
			return false;
		}

		glGenTextures(1, &TextureID);
		glBindTexture(GL_TEXTURE_2D, TextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, TextureWidth, TextureHeight, 0, (TextureChannels == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, TextureData);
		Transparent = (TextureChannels == 4) ? true : false;

		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(TextureData);
		std::cout << "Texture loaded correctly: " << pathName << std::endl;
		return true;
	}

	void Texture::StartUsingTexture() {
		if(Transparent){
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, TextureID);
	}

	void Texture::StopUsingTexture() {
		if (Transparent) {
			glDisable(GL_BLEND);
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}

	void Texture::UnloadTexture() {
		glDeleteTextures(1, & TextureID);
	}

}