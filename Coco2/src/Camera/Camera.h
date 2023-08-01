#ifndef CAMERA_H
#define CAMERA_H

#include "Entities/EntityBase.h"

namespace Coco2Engine {


	static class Camera : public EntityBase {

	private:
		virtual void Draw();
	protected:
	
		float Fov;
		float Width;
		float Height;
		float Near;
		float Far;

		Matrix4x4 ViewMatrix;
		Matrix4x4 ProjectionMatrix;

		unsigned int UniformViewMatrix;
		unsigned int UniformProjectionMatrix;

		void ReassignProjectionMatrix();

	public:
		Camera(Shader* ShaderToUse);

		void SetCameraFov(float Fov);
		void SetCameraWidth(float Width);
		void SetCameraHeight(float Height);
		void SetCameraNear(float Near);
		void SetCameraFar(float Far);

		Matrix4x4 GetViewMatrix() const {return ViewMatrix;	}
		Matrix4x4 GetProjectionMatrix() const { return ProjectionMatrix; }
	};

}


#endif