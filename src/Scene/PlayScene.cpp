#include "PlayScene.h"

//コンストラクタ
CPlayScene::CPlayScene()
{
	//ひとまず初期化にしておく
	eSceneID = PLAY_SCENE_INIT;
}


//デストラクタ
CPlayScene::~CPlayScene()
{
	//念の為
	Exit();
}

//ループ処理
int CPlayScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case PLAY_SCENE_INIT:
		Init();
		eSceneID = PLAY_SCENE_LAOD;
		break;

	case PLAY_SCENE_LAOD:
		Load();
		eSceneID = PLAY_SCENE_LOOP;
		break;

	case PLAY_SCENE_LOOP:
		Step();
		break;

	case PLAY_SCENE_END:
		Exit();
		eSceneID = PLAY_SCENE_INIT;
		iRet = 1;
		break;

	default:
		break;
	}

	return iRet;
}


//初期化
void CPlayScene::Init()
{	

	for (int index = 0; index < 2; index++) {
		player[index].SetPlayerP(index);
		player[index].Init();
	}

}


//終了処理
void CPlayScene::Exit()
{
	eSceneID = PLAY_SCENE_INIT;
}


//データ読み込み
void CPlayScene::Load()
{
	for (int index = 0; index < 2; index++) {
		player[index].Load();
	}
}


//描画
void CPlayScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	for (int index = 0; index < 2; index++) {
		player[index].Draw();
	}
	for (int index = 0; index < 2; index++) {
		player[index].UiDraw();
	}
}


//本体処理
void CPlayScene::Step()
{
	//シーン終了処理
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = PLAY_SCENE_END;
	}

	for (int index = 0; index < 2; index++) {
		player[index].Step();
	}

	CDebugString::GetInstance()->AddString(0, 0, "プレイシーン");
}


//情報更新
void CPlayScene::UpData()
{
}
