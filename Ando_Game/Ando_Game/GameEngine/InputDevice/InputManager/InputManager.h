//#pragma once
//#include "../Pad/Pad.h"
//#include <memory>
//
//class InputManager
//{
//private:
//
//	//=======================================
//	//	���̓f�o�C�X�̐錾
//	//=======================================
//
//	//�W���C�p�b�h
//	std::shared_ptr<Pad> m_joyPad;
//
//	/*���̓f�o�C�X�̃V���O���g����*/
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
//	//	�O���擾�֐�
//	//=======================================
//
//	//�C���X�^���X�擾�֐�
//	static InputManager& GetInstance() { static InputManager instance; return instance; }
//
//	//�W���C�p�b�h�擾�֐�
//	static std::shared_ptr<Pad> GetJoyPad() { return GetInstance().m_joyPad; }
//};
//
