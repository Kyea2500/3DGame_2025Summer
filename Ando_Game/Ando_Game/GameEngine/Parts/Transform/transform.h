#pragma once
#include <DxLib.h>

class Transform
{
private:
	VECTOR m_position;
	VECTOR m_scale;		// ÉXÉPÅ[Éã
	VECTOR m_rotation;	// âÒì]

public:
	void SetPosition(const VECTOR& _pos) { m_position = _pos; }
	VECTOR GetPosition() const { return m_position; }

	void SetPositionX(float x) { m_position.x = x; }
	VECTOR GetPositionX() const { return VGet(m_position.x, 0, 0); }
	
	void SetPositionY(float y) { m_position.y = y; }
	VECTOR GetPositionY() const { return VGet(0, m_position.y, 0); }

	void SetPositionZ(float z) { m_position.z = z; }
	VECTOR GetPositionZ() const { return VGet(0, 0, m_position.z); }



	void Setscale(const VECTOR& _scale) { m_scale = _scale; }
	VECTOR GetScale() const { return m_scale; }

	void SetRotation(const VECTOR& _rotation) { m_rotation = _rotation; }
	VECTOR GetRotation() const { return m_rotation; }
};