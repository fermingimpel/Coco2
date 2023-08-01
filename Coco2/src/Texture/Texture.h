#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

namespace Coco2Engine {

	class Texture {

	private:
		unsigned int TextureID;
		int TextureWidth;
		int TextureHeight;
		int TextureBitDepth;
		int TextureChannels;
		unsigned char* TextureData;
		std::string TexturePath;
		std::string TextureName;
		bool Transparent;

	public:
		Texture();
		~Texture();

		bool LoadTexture(const std::string Path, const std::string Name);
		void UnloadTexture();

		void StartUsingTexture();
		void StopUsingTexture();
	};

}

#endif