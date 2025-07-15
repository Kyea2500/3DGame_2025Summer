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


Pad::Pad() : m_joyPad(0), m_prevJoyPad(0)
{
}

Pad::~Pad()
{
}

void Pad::Update()
{
	// 前のフレームに押されていたボタンの情報を覚えておく
	lastInput = padInput;
	// 個のフレームに押されているボタンの情報を取得する
	padInput = GetJoypadDirectInputState(DX_INPUT_PAD1, &m_joyPad);

	

	// ここでm_joyPadに現在のパッドの状態を設定する必要があります。
	// 例えば、GetJoypadDirectInputStateなどを使って取得します。
	// 現在は仮の実装として何もしないようにしています。
	// 実際には、パッドの状態を取得してm_joyPadに設定してください。
	m_prevJoyPad = m_joyPad;
		// 入力状態を取得
		if (GetJoypadDirectInputState(DX_INPUT_PAD1, &m_joyPad))
		{
			assert(false && "Error: Failed to get joypad state.");
			return;
		}

}

//bool Pad::IsPress(int button) const
//{
//	// ここでは、ボタンが押されているかどうかをチェックします。
//// 実際には、m_joyPadの状態を確認して、ボタンが押されているかどうかを返す必要があります。
//	return (m_joyPad.Buttons[button] & 0x80) != 0; // ボタンが押されている場合はtrue,そうでない場合はfalseを返す
//}
//
//
//bool Pad::IsTrigger(int button) const
//{
//	// ここでは、ボタンが押された瞬間かどうかをチェックします。
//	// 実際には、m_joyPadの状態と前回の状態を比較して、ボタンが押された瞬間かどうかを返す必要があります。
//	return (m_joyPad.Buttons[button] & 0x80) && !(m_prevJoyPad.Buttons[button] & 0x80);
//}
