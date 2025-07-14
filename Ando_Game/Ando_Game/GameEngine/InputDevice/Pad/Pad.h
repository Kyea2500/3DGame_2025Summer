#pragma once  
#include <DxLib.h>  

namespace  
{  
constexpr float k_axisMax = 32767.0f; // スティックの最大値  
}  

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

class Pad  
{  
private:  
DINPUT_JOYSTATE m_joyPad;  
// 前回の状態を保存するための変数  
DINPUT_JOYSTATE m_prevJoyPad;  

// パッドの入力状態を更新するための定数  
constexpr static int k_axisMax = 32767;  

// 右スティックの構造体  
struct RightStick  
{  
	const DINPUT_JOYSTATE& joyState;  
	float X() const { return joyState.Rx / k_axisMax; }  
	float Y() const { return joyState.Ry / k_axisMax; }  
	float Z() const { return joyState.Rz / k_axisMax; }  
};  

// 左スティックの構造体  
struct LeftStick  
{  
	const DINPUT_JOYSTATE& joyState;  
	float X() const { return joyState.X / k_axisMax; }  
	float Y() const { return joyState.Y / k_axisMax; }  
	float Z() const { return joyState.Z / k_axisMax; }  
};  

public:  
	Pad();  
	~Pad();  
	void Update(); // パッドの入力状態を更新  
	bool IsPress(int button) const;
	bool IsTrigger(int button) const;

	RightStick GetRightStick() const { return RightStick{ m_joyPad }; }  
	LeftStick GetLeftStick() const { return LeftStick{ m_joyPad }; }  
};
