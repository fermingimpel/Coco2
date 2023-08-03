#include "Sprite.h"

#include <iostream>

#include <glew/glew.h>
#include <glfw/glfw3.h>

#include "Extras/GameplayStatics.h"
#include "Shader/Shader.h"

namespace Coco2Engine {

	Sprite::Sprite(std::string TexturePath, std::string TextureName) : Square() {
		SpriteAnimation = nullptr;
		HasAnimations = false;

		LoadTexture(TexturePath, TextureName);
	}

	Sprite::~Sprite() {
		if (SpriteAnimation)
			delete SpriteAnimation;
	}

	void Sprite::Draw() {
		if (!HasTextureLoaded) {
			std::cout << "ERROR!: Cant Draw a Sprite without texture loaded" << std::endl;
			return;
		}
		
		glUseProgram(Coco2_GetMainShader()->GetShader());
		glBindVertexArray(VertexArrayObject);

		if (HasAnimations) {
			if (SpriteAnimation->UpdateAnimation()) {
				SpriteAnimation->ChangeFrame(EntityVertexs);

				glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
				glBufferData(GL_ARRAY_BUFFER, EntityVertexs.size() * sizeof(float), &EntityVertexs.front(), GL_STATIC_DRAW);

				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
				glEnableVertexAttribArray(2);
			}
		
		}

		glEnable(GL_DEPTH_TEST);

		UpdateMVP();
		glUniform1i(UniformUseTexture, HasTextureLoaded);

		EntityTexture->StartUsingTexture();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		EntityTexture->StopUsingTexture();

		glUseProgram(0);
		glBindVertexArray(0);
	}

	void Sprite::CreateNewAnimation(int Columns, int Rows, int RowToUse, float TimeBetweenFrames, int AnimationFrames, std::string AnimationName) {
		if (!HasAnimations) {
			SpriteAnimation = new TextureAnimation();
			HasAnimations = true;
		}

		SpriteAnimation->CreateNewAnimation(Columns, Rows, RowToUse,TimeBetweenFrames, AnimationFrames, 
			EntityTexture->TextureWidth, EntityTexture->TextureHeight, AnimationName);

		SpriteAnimation->ChangeFrame(EntityVertexs);
	}

	void Sprite::ChangeCurrentAnimation(int AnimationIndex) {
		if (!HasAnimations) {
			std::cout << "ERROR!: Cant use ChangeCurrentAnimation withouts animations - Use CreateNewAnimation to create an animation with the Texture Loaded" << std::endl;
		
			return;
		}

		SpriteAnimation->ChangeCurrentAnimation(AnimationIndex);
	}

	Animation Sprite::GetCurrentAnimation() {

		if (!HasAnimations) {

			std::cout << "ERROR!: Cant use GetCurrentAnimation withouts animations - Use CreateNewAnimation to create an animation with the Texture Loaded" << std::endl;
			Animation a;
			return a;
		}

		return SpriteAnimation->GetCurrentAnimation();
	}

}