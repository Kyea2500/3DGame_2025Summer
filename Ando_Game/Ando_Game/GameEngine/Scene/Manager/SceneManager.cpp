#include "SceneManager.h"

SceneManager::SceneManager()
	: m_Kind(kSceneTitle), // 初期シーンをタイトルに設定
	m_pSceneTitle(nullptr),
	m_pSceneMain(nullptr),
	m_pSceneClera(nullptr)
{

}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
}

void SceneManager::End()
{
}

void SceneManager::Update()
{
}

void SceneManager::Draw()
{
}
