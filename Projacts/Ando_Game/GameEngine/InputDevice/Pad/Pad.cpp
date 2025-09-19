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
	padInput = GetJoypadXInputState(DX_INPUT_PAD1, 0);

	

	// ここでm_joyPadに現在のパッドの状態を設定する必要があります。
	// 例えば、GetJoypadDirectInputStateなどを使って取得します。
	// 現在は仮の実装として何もしないようにしています。
	// 実際には、パッドの状態を取得してm_joyPadに設定してください。
	m_prevJoyPad = m_joyPad;
		// 入力状態を取得
		if (GetJoypadXInputState(DX_INPUT_PAD1,0))
		{
			assert(false && "ゲームパッドが確認されませんでした");
			return;
		}

}

