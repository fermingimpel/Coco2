#include "Camera.h"

namespace Coco2Engine {
	void Camera::Draw() {}

	void Camera::ReassignProjectionMatrix() {
		ProjectionMatrix = glm::perspective(glm::radians(Fov), Width / Height, Near, Far);
	}

	Camera::Camera(Shader* ShaderToUse) : EntityBase(nullptr) {
		Fov = 45.0f;
		Width = 1366.0f;
		Height = 768.0f;
		Near = 0.1f;
		Far = 1000.0f;
		ReassignProjectionMatrix();

		ViewMatrix = glm::mat4(1.0f);
	}

	void Camera::SetCameraFov(float Fov) {
		this->Fov = Fov;
		ReassignProjectionMatrix();
	}

	void Camera::SetCameraWidth(float Width) {
		this->Width = Width;
		ReassignProjectionMatrix();
	}

	void Camera::SetCameraHeight(float Height) {
		this->Height = Height;
		ReassignProjectionMatrix();
	}

	void Camera::SetCameraNear(float Near) {
		this->Near = Near;
		ReassignProjectionMatrix();
	}

	void Camera::SetCameraFar(float Far) {
		this->Far = Far;
		ReassignProjectionMatrix();
	}

}