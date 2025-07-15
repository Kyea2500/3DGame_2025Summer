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

// POV方向（十字キー）
enum class PadPOVDirection
{
	UP = 0,
	RIGHT = 9000,
	DOWN = 18000,
	LEFT = 27000,
	NONE = -1
};

class Pad
{
private:
	DINPUT_JOYSTATE m_joyPad;
	// 前回の状態を保存するための変数  
	DINPUT_JOYSTATE m_prevJoyPad;

	// 右スティックの構造体  
	struct RightStick
	{
		const DINPUT_JOYSTATE& joyState;
		float X() const { return joyState.Rx / k_axisMax; }
		float Y() const { return joyState.Ry / k_axisMax; }
		float Z() const { return joyState.Rz / k_axisMax; }

		bool UP() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::UP); }
		bool RIGHT() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::RIGHT); }
		bool DOWN() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::DOWN); }
		bool LEFT() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::LEFT); }
	};

	// 左スティックの構造体  
	struct LeftStick
	{
		const DINPUT_JOYSTATE& joyState;
		float X() const { return joyState.X / k_axisMax; }
		float Y() const { return joyState.Y / k_axisMax; }
		float Z() const { return joyState.Z / k_axisMax; }

		bool UP() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::UP); }
		bool RIGHT() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::RIGHT); }
		bool DOWN() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::DOWN); }
		bool LEFT() const { return joyState.POV[0] == static_cast<int>(PadPOVDirection::LEFT); }
	};

	// ボタンの構造体
	struct Button
	{
		const DINPUT_JOYSTATE& joyState;
		const DINPUT_JOYSTATE& m_prevJoyPad;
		bool IsPress(int button) { return(joyState.Buttons) != 0; }// ボタンが押されている場合はtrue,そうでない場合はfalseを返す
		bool IsTrigger(int button) const { return (joyState.Buttons) && !(m_prevJoyPad.Buttons); }
	};



public:
	Pad();
	~Pad();
	void Update(); // パッドの入力状態を更新  

	RightStick GetRightStick() const { return RightStick{ m_joyPad }; }
	LeftStick GetLeftStick() const { return LeftStick{ m_joyPad }; }
	Button GetButton() const { return Button{ m_joyPad, m_prevJoyPad }; }
};
