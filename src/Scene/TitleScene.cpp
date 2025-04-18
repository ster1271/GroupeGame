#include "TitleScene.h"

#define ALPHA_MAX (255) // �A���t�@�l�̍ő�l
#define START_POSX (0.0f)
#define START_POSY (0.0f)
#define END_POSX (1000.0f)
#define END_POSY (500.0f)

//�R���X�g���N�^
CTitleScene::CTitleScene()
{
	m_startTime = 0;
	m_NowTime = 0;
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	m_handle = -1;

	//�Ƃ肠�����������Ɉړ�������
	eSceneID = TITLE_SCENE_INIT;
}


//�f�X�g���N�^
CTitleScene::~CTitleScene()
{
	Exit();
}


//���[�v����
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


//������
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


//�I������
void CTitleScene::Exit()
{
	eSceneID = TITLE_SCENE_INIT;
}


//���[�h
void CTitleScene::Load()
{
	m_startTime = GetNowCount();	// �N�����Ă���̎��Ԃ��擾
	m_handle = LoadGraph("data/title/�t���C�S��.png");
	m_HoiigaHandle = LoadGraph("data/title/�z�C�[�K.png");

	// �摜�̍ŏ��̍��W�Ɖ摜�̌��������W�Ŋp�x���v�Z
	//m_TwoPointDistance = sqrt((END_POSX - m_PosX) * (END_POSX - m_PosX) + (END_POSY - m_PosY) * (END_POSX - m_PosY)); 

	m_TwoPointRadius = atan2f((END_POSX - m_PosX), (END_POSY - m_PosY));

}


//�`��
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


//���g�̏���
void CTitleScene::Step()
{

	ImageMove(START_POSX, START_POSY, END_POSX, END_POSY, 80, 2, &m_PosX, &m_PosY);
		
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = TITLE_SCENE_END;
	}

	CDebugString::GetInstance()->AddString(0, 0, "�^�C�g���V�[��");
}


//���X�V
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

