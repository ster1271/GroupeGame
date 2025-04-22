#include "TitleScene.h"

#define ALPHA_MAX (255) // アルファ値の最大値
#define START_POSX (0.0f)
#define START_POSY (0.0f)
#define END_POSX (1000.0f)
#define END_POSY (500.0f)

#define TITLE_HANDLE ("data/title/REDHEAT_GUNFIGHT.png")
#define PLEASE_BUTTON_HANDLE ("data/title/プリーズAボタン.png")

//コンストラクタ
CTitleScene::CTitleScene()
{
	m_startTime = 0;
	m_NowTime = 0;
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	m_handle = -1;
	m_TitleBackGroundHndle = -1;

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
	m_FadeAlpha = 0.0f;
	m_BlinkFlag = false;
	m_FadeBlinkFlag = false;
	m_handle = -1;
	m_HoiigaHandle = -1;
	Music = -1;

}


//終了処理
void CTitleScene::Exit()
{
	eSceneID = TITLE_SCENE_INIT;
	StopSoundMem(Music);
	InitSoundMem();
}


//ロード
void CTitleScene::Load()
{
	m_startTime = GetNowCount();	// 起動してからの時間を取得

	m_handle = LoadGraph("data/title/フライゴン.png");
	m_HoiigaHandle = LoadGraph("data/title/ホイーガ.png");
	m_TitleBackGroundHndle = LoadGraph(TITLE_HANDLE);
	m_PleaseButtobnHandle = LoadGraph(PLEASE_BUTTON_HANDLE);
	m_FadeAlpha = 255.0;

	Music = LoadSoundMem("data/title/戦闘曲.mp3");
	ChangeVolumeSoundMem(255 * 60 / 100, Music);
	PlaySoundMem(Music, DX_PLAYTYPE_LOOP, true);

	// 画像の最初の座標と画像の向かう座標で角度を計算
	//m_TwoPointDistance = sqrt((END_POSX - m_PosX) * (END_POSX - m_PosX) + (END_POSY - m_PosY) * (END_POSX - m_PosY)); 

	m_TwoPointRadius = atan2f((END_POSX - m_PosX), (END_POSY - m_PosY));

}


//描画
void CTitleScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	DrawGraph(0, 0, m_TitleBackGroundHndle, false);

	

	SetDrawBlendMode(DX_BLENDMODE_ALPHA,(int)m_alpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, (int)m_alpha);

	ImageBlink(SCREEN_SIZE_X /2, 600, m_PleaseButtobnHandle, &m_alpha2, 2, &m_BlinkFlag, 0.5,0);

	ImageBlinkBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, &m_FadeAlpha, 0.0f, &m_FadeBlinkFlag, 0.0f, 2.0f );

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

void CTitleScene::ImageBlink(int Pos_X,int Pos_Y, int Handle, float *p_Alpha, float BlinkSpeed, bool *p_BlinkFlag ,float AddPace,float SubPace)
{

	float Alpha = *p_Alpha;
	float BlinkFlag = *p_BlinkFlag;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)Alpha);
	DrawRotaGraph(Pos_X, Pos_Y, 1.0f, 0.0f, Handle, true);
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

void CTitleScene::ImageBlinkBox(int Pos_x, int Pos_Y, int SizeX, int SizeY, float* p_Alpha, float BlinkSpeed, bool* p_BlinkFlag, float AddPace, float SubPace)
{

	float Alpha = *p_Alpha;
	float BlinkFlag = *p_BlinkFlag;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)Alpha);

	DrawBox(Pos_x, Pos_Y, SizeX, SizeY, GetColor(0, 0, 0), true);

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



