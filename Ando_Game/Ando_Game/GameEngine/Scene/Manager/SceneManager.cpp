#include "SceneManager.h"
#include "../SceneTitle/SceneTitle.h"
#include "../SceneMain/SceneMain.h"
#include "../SceneClear/SceneClear .h"
#include"../../InputDevice/Pad/Pad.h"
#include "DxLib.h"

SceneManager::SceneManager()
	: m_Kind(kSceneTitle), // 初期シーンをタイトルに設定
	m_pSceneTitle(nullptr),
	m_pSceneMain(nullptr)
{

}

SceneManager::~SceneManager()
{
	if (m_pSceneTitle != nullptr)
	{
		m_pSceneTitle = nullptr; // タイトルシーンのポインタを解放
		delete m_pSceneTitle; // タイトルシーンのメモリを解放
	}
	else if (m_pSceneMain != nullptr)
	{
		m_pSceneMain = nullptr; // メインシーンのポインタを解放
		delete m_pSceneMain; // メインシーンのメモリを解放
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
	case SceneManager::kSceneNum:
	default:
		break;
	}
}

void SceneManager::End()
{

	switch (m_Kind)
	{
	case  SceneManager::kSceneTitle:
		m_pSceneTitle->End();
		delete m_pSceneTitle;
		m_pSceneTitle = nullptr; // タイトルシーンのポインタを解放

		break;
	case  SceneManager::kSceneMain:
		m_pSceneMain->End();
		delete m_pSceneMain;
		m_pSceneMain = nullptr; // メインシーンのポインタを解放
		break;
	case SceneManager::kSceneNum:
	default:
		break;
	}
}

void SceneManager::Update()
{
	// パッドの入力状態を更新
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

	case SceneManager::kSceneNum:
	default:
		break;
	}

	if (nextKind != m_Kind)
	{
		// 現在実行中のシーン(m_kind)の終了処理
		End();
		// 次のシーンに切り替え
		m_Kind = nextKind;
		// 切り替え後のシーンの初期化
		Init();
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
	
	case SceneManager::kSceneNum:
	default:
		break;
	}
}
