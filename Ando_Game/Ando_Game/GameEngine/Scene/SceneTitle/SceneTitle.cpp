#include "SceneTitle.h"
#include "DxLib.h"


SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{// �^�C�g���V�[���̏���������
	// �����ł͓��ɉ������Ȃ����A�K�v�ɉ����ď�����������ǉ����邱�Ƃ��ł���
	SetDrawScreen(DX_SCREEN_BACK); // �`���𗠉�ʂɐݒ�
	ClearDrawScreen(); // ����ʂ��N���A
	DrawString(100, 100, "Title Scene", GetColor(255, 255, 255)); // �^�C�g���e�L�X�g��`��
}

void SceneTitle::End()
{
}

void SceneTitle::Update()
{
	// �^�C�g���V�[���̍X�V����
	// �����ł͓��ɉ������Ȃ����A�K�v�ɉ����čX�V������ǉ����邱�Ƃ��ł���
	if (CheckHitKey(KEY_INPUT_RETURN)) // Enter�L�[�������ꂽ��
	{
		// ���̃V�[���֑J�ڂ��鏈����ǉ����邱�Ƃ��ł���
	}
}

void SceneTitle::Draw()
{
	// �^�C�g���V�[���̕`�揈��
	// �����ł͓��ɉ������Ȃ����A�K�v�ɉ����ĕ`�揈����ǉ����邱�Ƃ��ł���
	ClearDrawScreen(); // ����ʂ��N���A
	DrawString(100, 100, "Title Scene", GetColor(255, 255, 255)); // �^�C�g���e�L�X�g��`��
	ScreenFlip(); // ����ʂ�\��ʂɐ؂�ւ���
}
