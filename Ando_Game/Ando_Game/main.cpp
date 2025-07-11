#include "DxLib.h"
#include"GameEngine/InputDevice/Game.h"
#include"GameEngine/Scene/SceneMain/SceneMain.h"


namespace
{
	constexpr int MaxTime = 16667;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �t���X�N���[���ł͂Ȃ��A�E�B���h�E���[�h�ŊJ���悤�ɂ���
	ChangeWindowMode(Game::kDefaultWindowMode);
	SetWindowText("<Untitle>");
	// ��ʃT�C�Y
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);



	std::shared_ptr<SceneMain> Scene = std::make_shared<SceneMain>();	// �V�[���̃C���X�^���X���쐬
	Scene->Init();




	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[�����[�v
	while (ProcessMessage() == 0)
	{
		// ���[�v���n�܂������Ԃ��o���Ă���
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʂ��N���A��
		ClearDrawScreen();

		// �����ɃQ�[���̏���������
		Scene->Update();		// �V�[���̍X�V����
		Scene->Draw();		// �V�[���̕`�揈��
		



		// ��ʂ̐؂�ւ���҂K�v������
		ScreenFlip();
		//FPS(Frame Per Second)60�ɌŒ�


		// esc�L�[�ŏI��(��������I��)
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		while (GetNowHiPerformanceCount() - time< MaxTime)
		{
		}

	}

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	Scene->End();			// �V�[���̏I������

	return 0;				// �\�t�g�̏I�� 
}