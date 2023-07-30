#ifndef COCO2MATHS_H
#define COCO2MATHS_H

#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace Coco2Engine {

	typedef glm::vec3 Vector3;
	typedef glm::mat4x4 Matrix4x4;
	typedef glm::quat Quaternion;

	float Deg2Rad();
	Quaternion Coco2_EulerToQuat(Vector3 Euler);
	Vector3 Coco2_QuatXVec3(Quaternion Quat, Vector3 Vec);
}

#endif