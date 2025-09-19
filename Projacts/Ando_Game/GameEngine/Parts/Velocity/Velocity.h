#pragma once
#include <DxLib.h>
#include <cmath> // sqrtfを使用するために必要
class Velocity
{
private:
	VECTOR m_velocity; // 速度ベクトル
public:

	void SetVelocity(const VECTOR& velocity) { m_velocity = velocity; }
	VECTOR GetVelocity() const { return m_velocity; }
	float GetVelocityX() const { return m_velocity.x; }
	float GetVelocityY() const { return m_velocity.y; }
	float GetVelocityZ() const { return m_velocity.z; }
	void VectorNormalizeXZ()
	{
		float length = sqrtf(GetVelocityX() *GetVelocityX() +GetVelocityZ() *GetVelocityZ());
		if (length > 0.0f)
		{
			/*m_vec.x /= length;*/
		SetVelocityX(GetVelocityX() / length);
			/*m_vec.z /= length;*/
		SetVelocityZ(GetVelocityZ() / length);
		}
	}
	
	void SetVelocityX(float x) { m_velocity.x = x; }
	void SetVelocityY(float y) { m_velocity.y = y; }
	void SetVelocityZ(float z) { m_velocity.z = z; }
};


