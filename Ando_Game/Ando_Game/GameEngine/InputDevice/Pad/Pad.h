#pragma once
#include <DxLib.h>

namespace
{
	constexpr float k_axisMax = 32767.0f; // �X�e�B�b�N�̍ő�l
}

namespace PadInput
{
	// �v���g�^�C�v�錾

	/// <summary>
	/// �p�b�h�̓��͏�ԍX�V����
	/// 1�t���[����1��̂݌Ăяo��
	/// </summary>
	void Update();

	/// <summary>
	/// Press����̎擾
	/// </summary>
	/// <param name="button">������s�������{�^��</param>
	/// <returns>������Ă�����true,������Ă��Ȃ�������false</returns>
	bool IsPress(int button);

	/// <summary>
	/// Trigger����(�����ꂽ�u��)�̎擾
	/// </summary>
	/// <param name="button">������s�������{�^��</param>
	/// <returns>�{�^���������ꂽ�u��true,����ȊO��false</returns>
	bool IsTrigger(int button);

}
//enum class PadButton
//{
//	A =0,
//	B,
//	X,
//	Y,
//	LB,
//	RB,
//	BACK,
//	START,
//	STICKBL,
//	STICKBR
//};
//
//enum class PadPOVDirection
//{
//	UP = 0,
//	RIGHT = 9000,
//	DOWN = 18000,
//	LEFT = 27000,
//	NONE = -1
//};
//
//
//
//class Pad
//{
//private:
//	DINPUT_JOYSTATE m_joyPad;
//	// �O��̏�Ԃ�ۑ����邽�߂̕ϐ�
//	DINPUT_JOYSTATE m_prevJoyPad;
//	// �E�X�e�B�b�N�̍\����
//	struct RightStick
//	{
//		const DINPUT_JOYSTATE& joyState;
//		float X() const { return joyState.Rx / k_axisMax; }
//		float Y() const { return joyState.Ry / k_axisMax; }
//		float Z() const { return joyState.Rz / k_axisMax; }
//	};
//
//	// ���X�e�B�b�N�̍\����
//	struct LeftStick
//	{
//		const DINPUT_JOYSTATE& joyState;
//		float X() const { return joyState.X / k_axisMax; }
//		float Y() const { return joyState.Y / k_axisMax; }
//		float Z() const { return joyState.Z / k_axisMax; }
//	};
//	// �{�^������я\���L�[
//	struct Button
//	{
//		const DINPUT_JOYSTATE& joyState;
//		const DINPUT_JOYSTATE& prevJoyState;
//		// �ʏ�{�^��
//		struct NomalKey
//		{
//			const DINPUT_JOYSTATE& joyState;
//			const DINPUT_JOYSTATE& prevJoyState;
//			
//			bool A() const { return joyState.Buttons[static_cast<int>(PadButton::A)]; }
//			bool B() const { return joyState.Buttons[static_cast<int>(PadButton::B)]; }
//			bool X() const { return joyState.Buttons[static_cast<int>(PadButton::X)]; }
//			bool Y() const { return joyState.Buttons[static_cast<int>(PadButton::Y)]; }
//			bool LB() const { return joyState.Buttons[static_cast<int>(PadButton::LB)]; }
//			bool RB() const { return joyState.Buttons[static_cast<int>(PadButton::RB)]; }
//			bool BACK() const { return joyState.Buttons[static_cast<int>(PadButton::BACK)]; }
//			bool START() const { return joyState.Buttons[static_cast<int>(PadButton::START)]; }
//			bool STICKBL() const { return joyState.Buttons[static_cast<int>(PadButton::STICKBL)]; }
//			bool STICKBR() const { return joyState.Buttons[static_cast<int>(PadButton::STICKBR)]; }
//		
//		
//		};
//		// �\���L�[
//		struct CrossKey
//		{
//			const DINPUT_JOYSTATE& joyState;
//			const DINPUT_JOYSTATE& prevJoyState;
//
//			bool UP() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::UP); }
//			bool RIGHT() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::RIGHT); }
//			bool DOWN() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::DOWN); }
//			bool LEFT() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::LEFT); }
//			bool NONE() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::NONE); }
//
//		};
//
//		CrossKey GetCrossKey() const { return CrossKey{ joyState, prevJoyState };}
//	};
//
//public:
//	Pad();
//	~Pad();
//	void Update(); // �p�b�h�̓��͏�Ԃ��X�V
//	RightStick GetRightStick() const { return RightStick{ m_joyPad }; }
//	LeftStick GetLeftStick() const { return LeftStick{ m_joyPad }; }
//
//	Button GetButton() const { return Button{ m_joyPad, m_prevJoyPad }; }
//};