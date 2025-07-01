#include "Pad.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	int padInput = 0;  // ���݂̃t���[���̃p�b�h����
	int lastInput = 0; // �ЂƂO�̃t���[���̃p�b�h����
}

namespace PadInput
{
	void Update()
	{
		// �O�̃t���[���ɉ�����Ă����{�^���̏����o���Ă���
		lastInput = padInput;
		// �̃t���[���ɉ�����Ă���{�^���̏����擾����
		padInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}

	bool IsPress(int button)
	{
		return (padInput & button);
	}

	bool IsTrigger(int button)
	{
		// (padInput & button) == 0�̏ꍇfalse
		// ����ȊO�̏ꍇ��true������
		bool isNow = (padInput & button);
		bool isLast = (lastInput & button);
		return (isNow && !isLast);
	}
}

//Pad::Pad()
//{
//	memset(&m_joyPad, 0, sizeof(m_joyPad)); // �[��������
//	m_prevJoyPad = m_joyPad; // �O��̏�Ԃ�ۑ�
//}
//
//Pad::~Pad()
//{
//}
//
//void Pad::Update()
//{
//	m_prevJoyPad = m_joyPad;
//	// ���͏�Ԃ��擾
//	if (GetJoypadDirectInputState(DX_INPUT_PAD1, &m_joyPad))
//	{
//		assert(false && "Error: Failed to get joypad state.");
//		return;
//	}
//
//}
