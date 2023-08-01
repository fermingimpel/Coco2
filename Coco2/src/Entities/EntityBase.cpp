#include "EntityBase.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>

#include <iostream>

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

	void EntityBase::BindBuffers() {
		if (EntityVertexs.size() <= 0)
			return;

		glGenVertexArrays(1, &VertexArrayObject);
		glGenBuffers(1, &VertexBufferObject);
		glBindVertexArray(VertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);

		glBufferData(GL_ARRAY_BUFFER, EntityVertexs.size() * sizeof(float), &EntityVertexs.front(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBufferData(GL_ARRAY_BUFFER, EntityVertexs.size() * sizeof(float), &EntityVertexs.front(), GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBufferData(GL_ARRAY_BUFFER, EntityVertexs.size() * sizeof(float), &EntityVertexs.front(), GL_STATIC_DRAW);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void EntityBase::BindIndexs() {
		if (EntityIndexs.size() <= 0)
			return;

		glBindVertexArray(VertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);

		glGenBuffers(1, &ElementBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, EntityIndexs.size() * sizeof(float), &EntityIndexs.front(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void EntityBase::SetVertexsAndIndex() {}

	EntityBase::EntityBase(Shader* ShaderToUse) {
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

		EntityShader = ShaderToUse;
		HasTextureLoaded = false;
	}

	EntityBase::~EntityBase() {
		if (EntityTexture) {
			delete EntityTexture;
		}
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

	void EntityBase::LoadTexture(std::string TexturePath, std::string TextureName) {
		if (!EntityTexture) {
			EntityTexture = new Texture();
		}

		if (EntityTexture) {
			HasTextureLoaded = EntityTexture->LoadTexture(TexturePath, TextureName);
		}
	}

}