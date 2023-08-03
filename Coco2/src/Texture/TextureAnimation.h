#ifndef TEXTUREANIMATION_H
#define TEXTUREANIMATION_H

#include <vector>
#include <string>

namespace Coco2Engine {

	struct Coord {
		float U=0;
		float V=0;
	};

	struct Frame {
		Coord FrameCoords[4];
	};

	struct Animation {
		std::vector<Frame> Frames;
		float TimeBetweenFrames = 0;
		std::string AnimationName = "AnimationName";
		int AnimationActualFrame = 0;
	};

	class TextureAnimation {

	private:
		std::vector<Animation> Animations;
		int ActualAnimation = 0;
		float AnimationTimer = 0;
	protected:

	public:
		TextureAnimation();

		void CreateNewAnimation(int Columns, int Rows, int RowToUse, float TimeBetweenFrames, int AnimationFrames, int Width, int Height, std::string AnimationName);
		void ChangeFrame(std::vector<float>& Vertices);
		bool UpdateAnimation();
		void ChangeCurrentAnimation(int AnimationIndex);
		Animation GetCurrentAnimation();

	};

}

#endif