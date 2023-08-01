#ifndef ENTITYBASE_H
#define ENTITYBASE_H

#include "Extras/Coco2Maths.h"

#include "Shader/Shader.h"

#include "Texture/Texture.h"
		
#include <vector>

namespace Coco2Engine {

	class EntityBase {

	private:

		struct Transform {
			Vector3 position;
			Vector3 rotation;
			Vector3 scale;
			Quaternion rotationQuaternion;

			Vector3 forward;
			Vector3 up;
			Vector3 right;
		};

		struct Matrix {
			Matrix4x4 model;
			Matrix4x4 translate;
			Matrix4x4 rotationX;
			Matrix4x4 rotationY;
			Matrix4x4 rotationZ;
			Matrix4x4 scale;
		};

	protected:
		//Visuals
		Shader* EntityShader;
		Texture* EntityTexture;
		bool HasTextureLoaded;

		// -x-

		//Transforms
		Transform transform;
		Matrix matrix;

		void UpdateMatrixData();
		void UpdateTransformsData();

		// -x-

		//Vertexs Things
		std::vector<float> EntityVertexs;
		std::vector<unsigned int> EntityIndexs;

		unsigned int VertexSize;

		float* VertexBuffer;
		unsigned int VertexBufferObject;
		unsigned int VertexArrayObject;
		unsigned int ElementBufferObject;

		virtual void BindBuffers();
		virtual void BindIndexs();
		virtual void SetVertexsAndIndex();

		//-x-

	public:
		EntityBase(Shader* ShaderToUse);
		~EntityBase();

		//Transforms

		Vector3 GetEntityPosition() const { return transform.position; }
		Quaternion GetEntityRotationQuat() const { return transform.rotationQuaternion; }
		Vector3 GetEntityScale() const { return transform.scale; }
		Vector3 GetEntityRotationEuler() const { return transform.rotation;  }

		Vector3 GetEntityForwardVector() const { return transform.forward; }
		Vector3 GetEntityUpVector() const { return transform.up; }
		Vector3 GetEntityRightVector() const { return transform.right;  }

		void SetEntityPosition(Vector3 NewPosition);
		void SetEntityRotation(Vector3 NewRotation);
		void SetEntityScale(Vector3 NewScale);

		// -x-

		//Visuals
		void LoadTexture(std::string TexturePath, std::string TextureName);
		virtual void Draw() = 0;
	};

}

#endif