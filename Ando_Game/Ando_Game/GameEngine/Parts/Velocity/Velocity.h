#pragma once
#include <DxLib.h>
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
	
	void SetVelocityX(float x) { m_velocity.x = x; }
	void SetVelocityY(float y) { m_velocity.y = y; }
	void SetVelocityZ(float z) { m_velocity.z = z; }
};


