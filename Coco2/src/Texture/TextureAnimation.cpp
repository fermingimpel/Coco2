#include "TextureAnimation.h"

#include "Timer/Timer.h"

#include <iostream>

namespace Coco2Engine {

	TextureAnimation::TextureAnimation() {
	}

	void TextureAnimation::CreateNewAnimation(int Columns, int Rows, int RowToUse, float TimeBetweenFrames,
		int AnimationFrames, int Width, int Height, std::string AnimationName) {
			
		Animation NewAnimation;
		NewAnimation.TimeBetweenFrames = TimeBetweenFrames;
		NewAnimation.AnimationName = AnimationName;


		float FrameWidth = Width / Columns;
		float FrameHeight = Height / Rows;

		if (RowToUse <= 0)
			RowToUse = 1;
		if (RowToUse > Rows)
			RowToUse = Rows;

		for (int i = 0; i < AnimationFrames; i++) {
			Frame NewFrame;   
				  
			NewFrame.FrameCoords[3].U = (FrameWidth * (i+1)) / Width; 
			NewFrame.FrameCoords[3].V = (FrameHeight / Height) * RowToUse; 

			NewFrame.FrameCoords[2].U = (FrameWidth * (i + 1)) / Width; 
			NewFrame.FrameCoords[2].V = (FrameHeight / Height) * (RowToUse - 1); 

			NewFrame.FrameCoords[1].U = (FrameWidth * i) / Width;
			NewFrame.FrameCoords[1].V = (FrameHeight / Height) * (RowToUse - 1);

			NewFrame.FrameCoords[0].U = (FrameWidth * i) / Width; 
			NewFrame.FrameCoords[0].V = (FrameHeight / Height) * RowToUse;

			NewAnimation.Frames.push_back(NewFrame);
		}

		Animations.push_back(NewAnimation);
	}

	void TextureAnimation::ChangeFrame(std::vector<float>& Vertices) {
		Vertices[6] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[0].U;
		Vertices[14] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[1].U;
		Vertices[22] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[2].U;
		Vertices[30] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[3].U;

		Vertices[7] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[0].V;
		Vertices[15] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[1].V;
		Vertices[23] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[2].V;
		Vertices[31] = Animations[ActualAnimation].Frames[Animations[ActualAnimation].AnimationActualFrame].FrameCoords[3].V;
	}

	bool TextureAnimation::UpdateAnimation() {
		AnimationTimer += Timer::GetDeltaTime();

		if (AnimationTimer >= Animations[ActualAnimation].TimeBetweenFrames) {

			while (AnimationTimer > Animations[ActualAnimation].TimeBetweenFrames) {

				AnimationTimer -= Animations[ActualAnimation].TimeBetweenFrames;
				Animations[ActualAnimation].AnimationActualFrame++;

				if (Animations[ActualAnimation].AnimationActualFrame >= Animations[ActualAnimation].Frames.size()) {
					Animations[ActualAnimation].AnimationActualFrame = 0;
				}
			}
			return true;
		}
		return false;
	}

	void TextureAnimation::ChangeCurrentAnimation(int AnimationIndex) {
		if (AnimationIndex >= Animations.size() || AnimationIndex < 0) {
			std::cout << "ERROR!: ChangeCurrentAnimation bad Index: " << AnimationIndex << std::endl;
			return;
		}
		Animations[ActualAnimation].AnimationActualFrame = 0;

		ActualAnimation = AnimationIndex;
		AnimationTimer = 0;
	}

	Animation TextureAnimation::GetCurrentAnimation() {
		return Animations[ActualAnimation];
	}

}