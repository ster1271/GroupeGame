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
	cMap.Init();
	for (int index = 0; index < 2; index++) {
		player[index].SetPlayerP(index);
		player[index].Init();
	}

}


//終了処理
void CPlayScene::Exit()
{
	cMap.Exit();
	player[0].Fin();
	player[1].Fin();
	eSceneID = PLAY_SCENE_INIT;
}


//データ読み込み
void CPlayScene::Load()
{
	cMap.Load(CData::GetInstance()->GetMapID());
	for (int index = 0; index < 2; index++) {
		player[index].Load();
	}
}


//描画
void CPlayScene::Draw()
{
	CDebugString::GetInstance()->Draw();
	cMap.Draw();
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
	cCollisionManager.PlayerToPlayer(player);
	cCollisionManager.PlayerToBullet(player);
	cCollisionManager.BulletToMap(player, cMap);
	cCollisionManager.PlayerToMap(player,cMap);

	//勝敗をセット
	if (!player[0].GetAlive()) {
		CData::GetInstance()->SetPlayerWin(false);
		eSceneID = PLAY_SCENE_END;
	}
	if (!player[1].GetAlive()) {
		CData::GetInstance()->SetPlayerWin(true);
		eSceneID = PLAY_SCENE_END;
	}
}


//情報更新
void CPlayScene::UpData()
{
}
