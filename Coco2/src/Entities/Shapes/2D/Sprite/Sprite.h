#ifndef SPRITE_H
#define SPRITE_H

#include "Entities/Shapes/2D/Square/Square.h"
#include "Texture/TextureAnimation.h"
#include <string>

namespace Coco2Engine {

	class Sprite  : public Square {

	private:

	protected:
		TextureAnimation* SpriteAnimation;

		bool HasAnimations;

	public:
		Sprite(std::string TexturePath, std::string TextureName);
		~Sprite();

		virtual void Draw();

		void CreateNewAnimation(int Columns, int Rows, int RowToUse, float TimeBetweenFrames, int AnimationFrames, std::string AnimationName);
		void ChangeCurrentAnimation(int AnimationIndex);
		Animation GetCurrentAnimation();
	};

}

#endif