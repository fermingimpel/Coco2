#include "Camera.h"

#include <glew/glew.h>

#include "Extras/GameplayStatics.h"
#include "Shader/Shader.h"

namespace Coco2Engine {
	void Camera::Draw() {}

	void Camera::ReassignProjectionMatrix() {
		ProjectionMatrix = glm::perspective(glm::radians(Fov), Width / Height, Near, Far);
	}

	Camera::Camera() : EntityBase() {
		Fov = 45.0f;
		Width = 1366.0f;
		Height = 768.0f;
		Near = 0.1f;
		Far = 1000.0f;
		ReassignProjectionMatrix();

		ViewMatrix = glm::mat4(1.0f);

		UniformEyePosition = glGetUniformLocation(Coco2_GetMainShader()->GetShader(), "EyePosition");
		UpdateLookAt();

		SetEntityRotation(Vector3(0, 180, 0));

		BasePosition = GetEntityPosition();
		BaseRotation = GetEntityRotationEuler();
	}

	void Camera::SetEntityPosition(Vector3 NewPosition) {
		EntityBase::SetEntityPosition(NewPosition);
		UpdateLookAt();
		UpdateEyePosition();
	}

	void Camera::SetEntityRotation(Vector3 NewRotation) {
		EntityBase::SetEntityRotation(NewRotation);
		UpdateLookAt();
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

	void Camera::ResetCamera() {
		SetEntityPosition(BasePosition);
		SetEntityRotation(BaseRotation);
	}

	void Camera::UpdateLookAt() {
		ViewMatrix = glm::lookAt(transform.position, transform.position + transform.forward, Vector3(0, 1, 0));
	}

	void Camera::UpdateEyePosition() {
		glUseProgram(Coco2_GetMainShader()->GetShader());
		glUniform3f(UniformEyePosition, transform.position.x, transform.position.y, transform.position.z);
		glUseProgram(0);
	}

}