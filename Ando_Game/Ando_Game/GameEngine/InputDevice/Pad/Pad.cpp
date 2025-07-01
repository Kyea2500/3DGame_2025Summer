#include "Pad.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	int padInput = 0;  // 現在のフレームのパッド入力
	int lastInput = 0; // ひとつ前のフレームのパッド入力
}

namespace PadInput
{
	void Update()
	{
		// 前のフレームに押されていたボタンの情報を覚えておく
		lastInput = padInput;
		// 個のフレームに押されているボタンの情報を取得する
		padInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}

	bool IsPress(int button)
	{
		return (padInput & button);
	}

	bool IsTrigger(int button)
	{
		// (padInput & button) == 0の場合false
		// それ以外の場合はtrueが入る
		bool isNow = (padInput & button);
		bool isLast = (lastInput & button);
		return (isNow && !isLast);
	}
}

//Pad::Pad()
//{
//	memset(&m_joyPad, 0, sizeof(m_joyPad)); // ゼロ初期化
//	m_prevJoyPad = m_joyPad; // 前回の状態を保存
//}
//
//Pad::~Pad()
//{
//}
//
//void Pad::Update()
//{
//	m_prevJoyPad = m_joyPad;
//	// 入力状態を取得
//	if (GetJoypadDirectInputState(DX_INPUT_PAD1, &m_joyPad))
//	{
//		assert(false && "Error: Failed to get joypad state.");
//		return;
//	}
//
//}
