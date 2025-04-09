#pragma once
#include "../Common.h"

class CTitleScene
{
private:
	enum tagTITLE_SCENE
	{
		TITLE_SCENE_INIT,
		TITLE_SCENE_LAOD,
		TITLE_SCENE_LOOP,
		TITLE_SCENE_END,

		TITLE_SCENE_NUM
	};

	tagTITLE_SCENE eSceneID;

	int m_startTime;	// 起動してからの時間
	int m_NowTime;		// 現在の時間

public:
	//コンストラクタ・デストラクタ
	CTitleScene();
	~CTitleScene();

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
