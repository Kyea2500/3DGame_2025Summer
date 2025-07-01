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

	void Setscale(const VECTOR& _scale) { m_scale = _scale; }
	VECTOR GetScale() const { return m_scale; }

	void SetRotation(const VECTOR& _rotation) { m_rotation = _rotation; }
	VECTOR GetRotation() const { return m_rotation; }
};