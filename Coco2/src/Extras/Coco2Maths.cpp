#include "Coco2Maths.h"

namespace Coco2Engine {

	float Deg2Rad() {
		return (glm::pi<float>() * 2.0f) / 360.0f;
	}

	Quaternion Coco2Engine::Coco2_EulerToQuat(Vector3 Euler) {
		Euler *= Deg2Rad();

		float cy = cos(Euler.z * 0.5);
		float sy = sin(Euler.z * 0.5);
		float cp = cos(Euler.x * 0.5);
		float sp = sin(Euler.x * 0.5);
		float cr = cos(Euler.y * 0.5);
		float sr = sin(Euler.y * 0.5);

		glm::quat q;
		q.w = cr * cp * cy + sr * sp * sy;
		q.x = cr * sp * cy + sr * cp * sy;
		q.y = sr * cp * cy - cr * sp * sy;
		q.z = cr * cp * sy - sr * sp * cy;
		return q;
	}

	Vector3 Coco2Engine::Coco2_QuatXVec3(Quaternion Quat, Vector3 Vec) {
		float x2 = Quat.x * 2.0f;
		float y2 = Quat.y * 2.0f;
		float z2 = Quat.z * 2.0f;
		float xx2 = Quat.x * x2;
		float yy2 = Quat.y * y2;
		float zz2 = Quat.z * z2;
		float xy2 = Quat.x * y2;
		float xz2 = Quat.x * z2;
		float yz2 = Quat.y * z2;
		float wx2 = Quat.w * x2;
		float wy2 = Quat.w * y2;
		float wz2 = Quat.w * z2;

		Vector3 Result;
		Result.x = (1.0f - (yy2 + zz2)) * Vec.x + (xy2 - wz2) * Vec.y + (xz2 + wy2) * Vec.z;
		Result.y = (xy2 + wz2) * Vec.x + (1.0f - (xx2 + zz2)) * Vec.y + (yz2 - wx2) * Vec.z;
		Result.z = (xz2 - wy2) * Vec.x + (yz2 + wx2) * Vec.y + (1.0f - (xx2 + yy2)) * Vec.z;
		return Result;
	}

}