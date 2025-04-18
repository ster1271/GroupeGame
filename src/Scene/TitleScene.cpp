#include "TitleScene.h"

#define ALPHA_MAX (255) // アルファ値の最大値
#define START_POSX (0.0f)
#define START_POSY (0.0f)
#define END_POSX (1000.0f)
#define END_POSY (500.0f)

//コンストラクタ
CTitleScene::CTitleScene()
{
	m_startTime = 0;
	m_NowTime = 0;
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	m_handle = -1;

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
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	m_handle = -1;
	m_HoiigaHandle = -1;

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
	m_handle = LoadGraph("data/title/フライゴン.png");
	m_HoiigaHandle = LoadGraph("data/title/ホイーガ.png");

	// 画像の最初の座標と画像の向かう座標で角度を計算
	//m_TwoPointDistance = sqrt((END_POSX - m_PosX) * (END_POSX - m_PosX) + (END_POSY - m_PosY) * (END_POSX - m_PosY)); 

	m_TwoPointRadius = atan2f((END_POSX - m_PosX), (END_POSY - m_PosY));

}


//描画
void CTitleScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA,(int)m_alpha);

	DrawBox(150, 0, 20, 500, COLOR, true, 0);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, (int)m_alpha);


	Angle += 0.5;

	ImageBlink(m_handle, &m_alpha2, 2, &m_BlinkFlag, 0.5,0);
	DrawRotaGraph((int)m_PosX, (int)m_PosY,1,Angle, m_HoiigaHandle, true);


	DrawBox(200, 0, 300, 500, COLOR, true, 0);

	if(m_alpha < 255)
	m_alpha++;
}


//中身の処理
void CTitleScene::Step()
{

	ImageMove(START_POSX, START_POSY, END_POSX, END_POSY, 80, 2, &m_PosX, &m_PosY);
		
	if (CInput::IsKeyPush(KEY_INPUT_RETURN) || PadInput::Push(0,XINPUT_BUTTON_A) )
	{
		eSceneID = TITLE_SCENE_END;
	}

	CDebugString::GetInstance()->AddString(0, 0, "タイトルシーン");
}


//情報更新
void CTitleScene::UpData()
{
}

void CTitleScene::ImageMove(float StartPositionX, float StartPositionY, float EndPositionX, float EndPositionY,
							float MoveSpeed,int time, float* p_MovePositionX, float* p_MovePositionY)
{
	float Radius = 0.0f;
	float MovePositionX = 0.0f;
	float MovePositionY = 0.0f;

	Radius = atan2f((EndPositionX - StartPositionX), (EndPositionY - StartPositionY));

	MovePositionX = sinf(Radius) * (MoveSpeed / time);
	MovePositionY = cosf(Radius) * (MoveSpeed / time);

	if (EndPositionX < (*p_MovePositionX + MovePositionX))
	{
		*p_MovePositionX = END_POSX;
	}
	else
	{
		*p_MovePositionX += MovePositionX;
	}

	if (EndPositionY < (*p_MovePositionY + MovePositionY))
	{
		*p_MovePositionY = END_POSY;
	}
	else
	{
		*p_MovePositionY += MovePositionY;
	}


}

void CTitleScene::ImageBlink(int Handle, float *p_Alpha, float BlinkSpeed, bool *p_BlinkFlag ,float AddPace,float SubPace)
{

	float Alpha = *p_Alpha;
	float BlinkFlag = *p_BlinkFlag;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)Alpha);
	DrawGraph(350, 0, Handle, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, (int)Alpha);

	if (!BlinkFlag)
	{
	
		Alpha += BlinkSpeed + AddPace;

		if ((int)Alpha >= ALPHA_MAX)
		{
			Alpha = ALPHA_MAX;
			BlinkFlag = true;

		}
	}

	else if (BlinkFlag)
	{
		Alpha -= BlinkSpeed + SubPace;

		if (Alpha <= 0)
		{
			Alpha = 0;
			BlinkFlag = false;

		}
	}

	*p_Alpha = Alpha;
	*p_BlinkFlag = BlinkFlag;

}

