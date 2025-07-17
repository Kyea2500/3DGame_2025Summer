#include "SceneManager.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneMain/SceneMain.h"
#include "../SceneClear/SceneClear .h"
#include"../../InputDevice/Pad/Pad.h"
#include "DxLib.h"

SceneManager::SceneManager()
	: m_Kind(kSceneTitle), // 初期シーンをタイトルに設定
	m_pSceneTitle(nullptr),
	m_pSceneMain(nullptr),
	m_pSceneClear(nullptr)
{

}

SceneManager::~SceneManager()
{
	if (m_pSceneTitle != nullptr)
	{
		m_pSceneTitle = nullptr; // タイトルシーンのポインタを解放
		delete m_pSceneTitle; // タイトルシーンのメモリを解放
	}
	if (m_pSceneMain != nullptr)
	{
		m_pSceneMain = nullptr; // メインシーンのポインタを解放
		delete m_pSceneMain; // メインシーンのメモリを解放
	}
	if (m_pSceneClear != nullptr)
	{
		m_pSceneClear = nullptr; // ゲームクリアシーンのポインタを解放
		delete m_pSceneClear; // ゲームクリアシーンのメモリを解放
	}
}

void SceneManager::Init()
{
	switch (m_Kind)
	{
	case SceneManager::kSceneTitle:
		//m_pSceneTitle = std::make_shared<SceneTitle>();
		m_pSceneTitle = new SceneTitle;
		m_pSceneTitle->Init();
		break;
	case  SceneManager::kSceneMain:
	/*	m_pSceneMain = std::make_shared<SceneMain>();*/
		m_pSceneMain = new SceneMain;
		m_pSceneMain->Init();
		break;
	case  SceneManager::kSceneClear:
		/*m_pSceneClear = std::make_shared<SceneClear>();*/
		m_pSceneClear = new SceneClear;
		m_pSceneClear->Init();
		break;
	default:
		break;
	}
}

void SceneManager::End()
{

	switch (m_Kind)
	{
	case  SceneManager::kSceneTitle:
		if (m_pSceneTitle != nullptr)
		{
			m_pSceneTitle->End();
			m_pSceneTitle = nullptr; // タイトルシーンのポインタを解放
		}
		break;
	case  SceneManager::kSceneMain:
		if (m_pSceneMain != nullptr)
		{
			m_pSceneMain->End();
			m_pSceneMain = nullptr; // メインシーンのポインタを解放
		}
		break;
	case  SceneManager::kSceneClear:
		if (m_pSceneClear != nullptr)
		{
			m_pSceneClear->End();
			m_pSceneClear = nullptr; // ゲームクリアシーンのポインタを解放
		}
		break;
	}
}

void SceneManager::Update()
{
	PadInput::Update();
	SceneKind nextKind = m_Kind;
	switch (m_Kind)
	{
	case  SceneManager::kSceneTitle:
		nextKind = m_pSceneTitle->Update();
		break;

	case  SceneManager::kSceneMain:
		nextKind = m_pSceneMain->Update();
		break;

	//case  SceneManager::kSceneClear:
	//	nextKind = m_pSceneClear->Update();
	//	break;

	default:
		break;
	}
}

void SceneManager::Draw()
{
	switch (m_Kind)
	{
	case  SceneManager::kSceneTitle:
		m_pSceneTitle->Draw();
		break;
	
	case  SceneManager::kSceneMain:
		m_pSceneMain->Draw();
		break;
	
	case  SceneManager::kSceneClear:
		m_pSceneClear->Draw();

		break;
	default:
		break;
	}
}
