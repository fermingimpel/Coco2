#ifndef ENTITYBASE_H
#define ENTITYBASE_H

#include "Extras/Coco2Maths.h"

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
		Texture* EntityTexture;
		bool HasTextureLoaded;

		// -x-

		//Transforms
		Transform transform;
		Matrix ModelMatrix;

		void UpdateMatrixData();
		void UpdateTransformsData();

		void UpdateMVP();

		// -x-

		//Vertexs Things
		std::vector<float> EntityVertexs;
		std::vector<unsigned int> EntityIndexs;

		unsigned int VertexSize;

		float* VertexBuffer;
		unsigned int VertexBufferObject;
		unsigned int VertexArrayObject;
		unsigned int ElementBufferObject;

		unsigned int UniformModelMatrix;
		unsigned int UniformViewMatrix;
		unsigned int UniformProjectionMatrix;
		unsigned int UniformUseTexture; 


		virtual void BindBuffers();
		virtual void BindIndexs();
		virtual void SetVertexsAndIndex();

		//-x-

	public:
		EntityBase();
		~EntityBase();

		//Transforms

		Vector3 GetEntityPosition() const { return transform.position; }
		Quaternion GetEntityRotationQuat() const { return transform.rotationQuaternion; }
		Vector3 GetEntityScale() const { return transform.scale; }
		Vector3 GetEntityRotationEuler() const { return transform.rotation;  }

		Vector3 GetEntityForwardVector() const { return transform.forward; }
		Vector3 GetEntityUpVector() const { return transform.up; }
		Vector3 GetEntityRightVector() const { return transform.right;  }

		virtual void SetEntityPosition(Vector3 NewPosition);
		virtual void SetEntityRotation(Vector3 NewRotation);
		virtual void SetEntityScale(Vector3 NewScale);


		virtual void AddEntityPosition(Vector3 ExtraPosition);
		virtual void AddEntityRotation(Vector3 ExtraRotation);
		virtual void AddEntityScale(Vector3 ExtraScale);

		// -x-

		//Visuals
		void LoadTexture(std::string TexturePath, std::string TextureName);
		virtual void Draw() = 0;
	};

}

#endif