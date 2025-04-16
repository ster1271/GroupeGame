#pragma once
#include "../Common.h"
#include "../Map/Map.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Data/Data.h"

//プレイシーンクラス
class CPlayScene
{
private:
	enum tagPLAY_SCENE
	{
		PLAY_SCENE_INIT,
		PLAY_SCENE_LAOD,
		PLAY_SCENE_LOOP,
		PLAY_SCENE_END,

		PLAY_SCENE_NUM
	};

	
	tagPLAY_SCENE eSceneID;

	Player player[2];
	CMap cMap;
	CCollisionManager cCollisionManager;

public:
	//コンストラクタ・デストラクタ
	CPlayScene();
	~CPlayScene();

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

	//情報更新
	void UpData();

};
