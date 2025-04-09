#include "TitleScene.h"


//コンストラクタ
CTitleScene::CTitleScene()
{
	//とりあえず初期化に移動させる
	eSceneID = TITLE_SCENE_INIT;
}


//デストラクタ
CTitleScene::~CTitleScene()
{
	Exit();
}


//ループ処理
int CTitleScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case TITLE_SCENE_INIT:
		Init();
		eSceneID = TITLE_SCENE_LAOD;
		break;

	case TITLE_SCENE_LAOD:
		Load();
		eSceneID = TITLE_SCENE_LOOP;
		break;

	case TITLE_SCENE_LOOP:
		Step();

		break;

	case TITLE_SCENE_END:
		Exit();
		iRet = 1;
		break;


	default:
		break;
	}

	return iRet;
}


//初期化
void CTitleScene::Init()
{

	m_startTime = 0;
	m_NowTime = 0;

}


//終了処理
void CTitleScene::Exit()
{
	eSceneID = TITLE_SCENE_INIT;
}


//ロード
void CTitleScene::Load()
{
	m_startTime = GetNowCount();	// 起動してからの時間を取得
}


//描画
void CTitleScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	DrawBox(150, 0, 20, 500, COLOR, true, 0);
}


//中身の処理
void CTitleScene::Step()
{
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = TITLE_SCENE_END;
	}

	CDebugString::GetInstance()->AddString(0, 0, "タイトルシーン");
}


//情報更新
void CTitleScene::UpData()
{
}

