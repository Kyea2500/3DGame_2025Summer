#pragma once
#include <DxLib.h>

namespace PadInput
{
	// プロトタイプ宣言

	/// <summary>
	/// パッドの入力状態更新処理
	/// 1フレームに1回のみ呼び出す
	/// </summary>
	void Update();

	/// <summary>
	/// Press判定の取得
	/// </summary>
	/// <param name="button">判定を行いたいボタン</param>
	/// <returns>押されていたらtrue,押されていなかったらfalse</returns>
	bool IsPress(int button);

	/// <summary>
	/// Trigger判定(押された瞬間)の取得
	/// </summary>
	/// <param name="button">判定を行いたいボタン</param>
	/// <returns>ボタンが押された瞬間true,それ以外はfalse</returns>
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
//	void Update(); // パッドの入力状態を更新
//};