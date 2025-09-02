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

	void SetScaleX(float x) { m_scale.x = x; }
	VECTOR GetScaleX() const { return VGet(m_scale.x, 0, 0); }
	void SetScaleY(float y) { m_scale.y = y; }
	VECTOR GetScaleY() const { return VGet(0, m_scale.y, 0); }
	void SetScaleZ(float z) { m_scale.z = z; }
	VECTOR GetScaleZ() const { return VGet(0, 0, m_scale.z); }


	void SetRotation(const VECTOR& _rotation) { m_rotation = _rotation; }
	VECTOR GetRotation() const { return m_rotation; }

	void SetRotationX(float x) { m_rotation.x = x; }
	VECTOR GetRotationX() const { return VGet(m_rotation.x, 0, 0); }

	void SetRotationY(float y) { m_rotation.y = y; }
	VECTOR GetRotationY() const { return VGet(0, m_rotation.y, 0); }

	void SetRotationZ(float z) { m_rotation.z = z; }
	VECTOR GetRotationZ() const { return VGet(0, 0, m_rotation.z); }
};