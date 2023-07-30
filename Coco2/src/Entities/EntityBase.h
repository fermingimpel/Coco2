#ifndef ENTITYBASE_H
#define ENTITYBASE_H

#include "Extras/Coco2Maths.h"
		
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
		Transform transform;
		Matrix matrix;

		void UpdateMatrixData();
		void UpdateTransformsData();

	public:
		EntityBase();
		~EntityBase();

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
	};

}

#endif