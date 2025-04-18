#pragma once
#include "../Common.h"
#include "../Data/Data.h"
#include "../Input/PadInput.h"

class CResultScene
{
public:
	enum SCENE_CURSOR
	{
		CURSOR_TITLE = 0,							// タイトルカーソル
		CURSOR_SELECT,								// セレクトカーソル
		CURSOR_PLAY,								// プレイカーソル

		CURSOR_NUMBER_NUM							// カーソルの数
	};

private:
	enum tagRESULT_SCENE
	{
		RESULT_SCENE_INIT,
		RESULT_SCENE_LAOD,
		RESULT_SCENE_LOOP,
		RESULT_SCENE_END,

		RESULT_SCENE_NUM
	};

	tagRESULT_SCENE eSceneID;
	SCENE_CURSOR e_SceneCuesor;

	bool m_WinFlag;
	int m_CursorNumber;
	bool m_IsDecideScene;

	void SceneSelect();


public:
	//コンストラクタ・デストラクタ
	CResultScene();
	~CResultScene();

	//ループ処理
	int Loop();

	//初期化
	void Init();

	//終了処理
	void Exit();

	//データ読み込み
	void Load();

	//描画
	void Draw();

	//本体処理
	void Step();

	SCENE_CURSOR GetSceneCursor() { return e_SceneCuesor; }
};

