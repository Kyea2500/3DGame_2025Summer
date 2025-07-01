//#pragma once
//#include "../Pad/Pad.h"
//#include <memory>
//
//class InputManager
//{
//private:
//
//	//=======================================
//	//	入力デバイスの宣言
//	//=======================================
//
//	//ジョイパッド
//	std::shared_ptr<Pad> m_joyPad;
//
//	/*入力デバイスのシングルトン化*/
//	InputManager();
//	~InputManager();
//
//	InputManager(const InputManager&) = delete;
//	InputManager& operator=(const InputManager&) = delete;
//
//
//public:
//
//	void InputUpdate();
//
//	//=======================================
//	//	外部取得関数
//	//=======================================
//
//	//インスタンス取得関数
//	static InputManager& GetInstance() { static InputManager instance; return instance; }
//
//	//ジョイパッド取得関数
//	static std::shared_ptr<Pad> GetJoyPad() { return GetInstance().m_joyPad; }
//};
//
