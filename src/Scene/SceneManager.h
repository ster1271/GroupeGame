#pragma once
#include "DxLib.h"
#include "PlayScene.h"
#include "TitleScene.h"
#include "ResultScene.h"

class SceneManager
{
private:
	enum tagSCENE
	{
		SCENE_TITLE,	//タイトル画面
		SCENE_PLAY,		//ゲーム中
		SCENE_RESULT,	//リザルト画面

		SCENE_NUM
	};

	tagSCENE eSceneID;				//シーン保存

	CTitleScene cTitleScene;		//タイトルシーン
	CPlayScene cPlayScene;			//プレイシーン
	CResultScene cResultScene;		//リザルトシーン

public:
	//コンストラクタ・デストラクタ
	SceneManager();
	~SceneManager();

	//ループ処理
	void Loop();

	//描画
	void Draw();

};