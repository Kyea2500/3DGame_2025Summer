#pragma once
#include <DxLib.h>

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
enum class PadButton
{
	A =0,
	B,
	X,
	Y,
	LB,
	RB,
	BACK,
	START,
	STICKBL,
	STICKBR
};

enum class PadPOVDirection
{
	UP = PAD_INPUT_UP,
	RIGHT = PAD_INPUT_RIGHT,
	DOWN = PAD_INPUT_DOWN,
	LEFT = PAD_INPUT_LEFT,

};



//class Pad
//{
//private:
//	DINPUT_JOYSTATE m_joyPad;
//
//public:
//	Pad();
//	~Pad();
//	void Update(); // �p�b�h�̓��͏�Ԃ��X�V
//};