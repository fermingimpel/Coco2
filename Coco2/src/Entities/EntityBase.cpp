#include "EntityBase.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

namespace Coco2Engine {

	void EntityBase::UpdateMatrixData() {
		matrix.model = matrix.translate * matrix.rotationX * matrix.rotationY * matrix.rotationZ * matrix.scale;
	}

	void EntityBase::UpdateTransformsData() {
		transform.rotationQuaternion = Coco2_EulerToQuat(transform.rotation);
		transform.forward = Coco2_QuatXVec3(transform.rotationQuaternion, glm::vec3(0, 0, 1));
		transform.up = Coco2_QuatXVec3(transform.rotationQuaternion, glm::vec3(0, 1, 0));
		transform.right = Coco2_QuatXVec3(transform.rotationQuaternion, glm::vec3(1, 0, 0));
	}

	EntityBase::EntityBase() {
		matrix.model = glm::mat4(1.0f);
		matrix.translate = glm::mat4(1.0f);
		matrix.rotationX = glm::mat4(1.0f);
		matrix.rotationY = glm::mat4(1.0f);
		matrix.rotationZ = glm::mat4(1.0f);
		matrix.scale = glm::mat4(1.0f);

		transform.position = { 0,0,0 };
		transform.scale = { 1,1,1 };
		transform.rotation = { 0,0,0 };

		transform.rotationQuaternion = glm::quat(0, 0, 0, 1);

		UpdateMatrixData();
		UpdateTransformsData();

		//EntityShader = Shader;
	}

	EntityBase::~EntityBase() {
	
	}

	void EntityBase::SetEntityPosition(Vector3 NewPosition) {
		transform.position = NewPosition;
		matrix.translate = glm::translate(glm::mat4(1.0f), transform.position);
		UpdateMatrixData();
	}

	void EntityBase::SetEntityRotation(Vector3 NewRotation) {
		transform.rotation = NewRotation;

		matrix.rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(NewRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		matrix.rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(NewRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		matrix.rotationZ = glm::rotate(glm::mat4(1.0f), glm::radians(NewRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		UpdateMatrixData();
		UpdateTransformsData();
	}

	void EntityBase::SetEntityScale(Vector3 NewScale) {
		transform.scale = NewScale;
		matrix.scale = glm::scale(glm::mat4(1.0f), transform.scale);
		UpdateMatrixData();
	}

}