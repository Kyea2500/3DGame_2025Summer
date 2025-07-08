#include "SceneMain.h"
#include "DxLib.h"
#include "../../GameObject/Player/Player.h"
#include "../../InputDevice/Camera/Camera.h"
#include"../../Parts/Transform/transform.h"
#include"../../GameObject/Map/Map.h"
#include "../../GameObject/Enemy/Enemy.h"


SceneMain::SceneMain()
	:m_playerHandle(-1), // �v���C���[�̃n���h���������� 
	m_mapHandle(-1), // �}�b�v�̃n���h����������
	m_pPlayer(nullptr), // �v���C���[�̃|�C���^��������
	m_pEnemy(nullptr),    // �G�̃|�C���^��������
	m_pCamera(nullptr), // �J�����̃|�C���^��������
	m_pMap(nullptr) // �}�b�v�̃|�C���^��������
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	// ���f����ǂݍ���
	m_playerHandle = MV1LoadModel("../../../../model/player.mv1");
	m_mapHandle = MV1LoadModel("data/model/Map.mv1");

	// �v���C���[�̏�����
	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetModel(m_playerHandle); // �v���C���[�̃��f���n���h����ݒ�
	m_pPlayer->Init();
	// �G�̏�����
	 m_pEnemy = std::make_shared<Enemy>();
	 m_pEnemy->SetModel(m_enemyHandle); // �G�̃��f���n���h����ݒ�
	 m_pEnemy->Init(); // �G�̏�����
	//Transform transform; // Transform�I�u�W�F�N�g���쐬

	// �J�����̏�����
	m_pCamera=std::make_shared<Camera>();
	m_pCamera->Init(); // �J�����̏�����

	// �}�b�v�̏�����
	m_pMap = std::make_shared<Map>();
	m_pMap->SetModel(m_mapHandle); // �}�b�v�̃��f���n���h����ݒ�
	m_pMap->Init(); // �}�b�v�̏�����

}

void SceneMain::End()
{
	MV1DeleteModel(m_playerHandle); // �v���C���[�̃��f�����폜
	MV1DeleteModel(m_mapHandle); // �}�b�v�̃��f�����폜
	 MV1DeleteModel(m_enemyHandle); // �G�̃��f�����폜�i�K�v�Ȃ�R�����g�A�E�g���O���j
	m_pPlayer->Final(); // �v���C���[�̏I������
	m_pCamera->End(); // �J�����̏I������
	m_pMap->End(); // �}�b�v�̏I������
	 m_pEnemy->End(); // �G�̏I�������i�K�v�Ȃ�R�����g�A�E�g���O���j
	
}

void SceneMain::Update()
{
	// �v���C���[�̍X�V����
	m_pPlayer->Update(); // �v���C���[�̍X�V
	// player�̑����ɒn�`�����邩
	
	// �v���C���[�̈ʒu���J�����̒����_�ɐݒ�
	m_pCamera->SetTarget(m_pPlayer->GetPos()); // �J�����̒����_���v���C���[�̈ʒu�ɐݒ�
	// �J�����̈ʒu���v���C���[�̈ʒu�ɐݒ�
	m_pCamera->SetHAngle(m_pPlayer->GetPos().x);
	m_pCamera->SetVAngle(m_pPlayer->GetPos().y);
	// �J�����̍X�V����
	m_pCamera->Update(); // �J�����̍X�V
	
	// �G�̃v���C���[�̈ʒu���擾
	m_pEnemy->SetPlayer(m_pPlayer->GetPos()); // �G�Ƀv���C���[�̈ʒu��ݒ�
	// �G�̍X�V����
	 m_pEnemy->Update(); // �G�̍X�V
	// �}�b�v�̍X�V����
	m_pMap->Update(); // �}�b�v�̍X�V

	// �v���C���[�ƓG�Ƃ̓����蔻��


}

void SceneMain::Draw()
{
	// �v���C���[�̕`�揈��
	m_pPlayer->Draw();
	// �G�̕`�揈��
	 m_pEnemy->Draw(); // �G�̕`��
	// �}�b�v�̕`�揈��
	m_pMap->Draw(); // �}�b�v�̕`��
}