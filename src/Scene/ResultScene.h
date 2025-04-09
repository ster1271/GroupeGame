#pragma once
#include "../Common.h"

class CResultScene
{
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
};

