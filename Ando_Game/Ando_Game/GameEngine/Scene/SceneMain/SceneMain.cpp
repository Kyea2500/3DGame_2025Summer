#include "SceneMain.h"
#include "DxLib.h"
#include "../../GameObject/Player/Player.h"
#include "../../InputDevice/Camera/Camera.h"
#include"../../Parts/Transform/transform.h"


namespace
{
	// �O���b�h�̃T�C�Y
	constexpr int kGridSize = 100;
	// �O���b�h�͈̔�
	constexpr int kGridRange = 500;
	// �c�O���b�h�̐F
	constexpr int kGridColorZ = 0xff0000; // �ԐF
	// ���O���b�h�̐F
	constexpr int kGridColorX = 0x0000ff; // �F
}

SceneMain::SceneMain()
	:m_playerHandle(-1), // �v���C���[�̃n���h���������� 
	m_pPlayer(nullptr), // �v���C���[�̃|�C���^��������
	m_pEnemy(nullptr),    // �G�̃|�C���^��������
	m_pCamera(nullptr) // �J�����̃|�C���^��������
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	// ���f����ǂݍ���
	m_playerHandle = MV1LoadModel("Ando_Game/data/model/player2.mv1");
	// m_enemyHandle = MV1LoadModel("data/model/Enemy.mv1"); // �G�̃��f����ǂݍ��ށi�K�v�Ȃ�R�����g�A�E�g���O���j

	// �v���C���[�̏�����
	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetModel(m_playerHandle); // ���f���n���h����ݒ�
	m_pPlayer->Init();
	// �G�̏�����
	// m_pEnemy = std::make_shared<enemy>();
	// m_pEnemy->SetModel(m_enemyHandle); // �G�̃��f���n���h����ݒ�
	// m_pEnemy->Init(); // �G�̏�����
	Transform transform; // Transform�I�u�W�F�N�g���쐬

	// �J�����̏�����
	m_pCamera=std::make_shared<Camera>();
	m_pCamera->Init(); // �J�����̏�����


}

void SceneMain::End()
{
	MV1DeleteModel(m_playerHandle);
	//	MV1DeleteModel(m_enemyHandle);
}

void SceneMain::Update()
{
	// �v���C���[�̍X�V����
	m_pPlayer->Update();
	// �J�����̍X�V����
	m_pCamera->Update(); // �J�����̍X�V
	
	// �G�̍X�V����
	// m_pEnemy->Update(); // �G�̍X�V�i�K�v�Ȃ�R�����g�A�E�g���O���j
}

void SceneMain::Draw()
{
	DrawGrid();
	// �v���C���[�̕`�揈��
	m_pPlayer->Draw();
	// �G�̕`�揈��
	// m_pEnemy->Draw(); // �G�̕`��i�K�v�Ȃ�R�����g�A�E�g���O���j


}

void SceneMain::DrawGrid() const
{
	for (int z = -kGridRange; z <= kGridRange; z += kGridSize)
	{
		DrawLine3D(VGet(-kGridRange, 0, z), VGet(kGridRange, 0, z), 0xff0000);
	}
	for (int x = -kGridRange; x <= kGridRange; x += kGridSize)
	{
		DrawLine3D(VGet(x, 0, -kGridRange), VGet(x, 0, kGridRange), 0x0000ff);
	}
}
