#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

namespace Coco2Engine {

	class Texture {

	private:
		unsigned int TextureID;
		unsigned char* TextureData;

	public:
		int TextureWidth;
		int TextureHeight;
		int TextureBitDepth;
		int TextureChannels;

		std::string TexturePath;
		std::string TextureName;
		bool Transparent;

		Texture();
		~Texture();

		bool LoadTexture(const std::string Path, const std::string Name);
		void UnloadTexture();

		void StartUsingTexture();
		void StopUsingTexture();
	};

}

#endif