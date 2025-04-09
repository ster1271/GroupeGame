#include "ResultScene.h"


//コンストラクタ
CResultScene::CResultScene()
{
	//とりあえず初期化に移動させる
	eSceneID = RESULT_SCENE_INIT;
}


//デストラクタ
CResultScene::~CResultScene()
{
	Exit();
}


//ループ処理
int CResultScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case RESULT_SCENE_INIT:
		Init();
		eSceneID = RESULT_SCENE_LAOD;
		break;

	case RESULT_SCENE_LAOD:
		Load();
		eSceneID = RESULT_SCENE_LOOP;
		break;

	case RESULT_SCENE_LOOP:
		Step();
		break;

	case RESULT_SCENE_END:
		Exit();
		iRet = 1;
		break;


	default:
		break;
	}

	return iRet;
}


//初期化
void CResultScene::Init()
{
}


//終了処理
void CResultScene::Exit()
{
	eSceneID = RESULT_SCENE_INIT;
}


//データ読み込み
void CResultScene::Load()
{
}

//本体処理
void CResultScene::Step()
{
	//シーン終了処理
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = RESULT_SCENE_END;
	}

	CDebugString::GetInstance()->AddString(0, 0, "リザルトシーン");
}

//描画
void CResultScene::Draw()
{
	CDebugString::GetInstance()->Draw();
}
