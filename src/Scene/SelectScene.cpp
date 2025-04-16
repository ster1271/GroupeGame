#include "SelectScene.h"

#define ALPHA_MAX (255) // �A���t�@�l�̍ő�l

//�R���X�g���N�^
CSelectScene::CSelectScene()
{
	m_startTime = 0;
	m_NowTime = 0;
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	for (int i = 0; i < SELECT_IMAGE_NUM; i++)
	{
		m_handle[i] = -1;
	}

	//�Ƃ肠�����������Ɉړ�������
	eSceneID = SELECT_SCENE_INIT;
}


//�f�X�g���N�^
CSelectScene::~CSelectScene()
{
	Exit();
}


//���[�v����
int CSelectScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case SELECT_SCENE_INIT:
		Init();
		eSceneID = SELECT_SCENE_LAOD;
		break;

	case SELECT_SCENE_LAOD:
		Load();
		eSceneID = SELECT_SCENE_LOOP;
		break;

	case SELECT_SCENE_LOOP:
		Step();

		break;

	case SELECT_SCENE_END:
		Exit();
		iRet = 1;
		break;


	default:
		break;
	}

	return iRet;
}


//������
void CSelectScene::Init()
{

	m_startTime = 0;
	m_NowTime = 0;
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	for (int i = 0; i < SELECT_IMAGE_NUM; i++)
	{
		m_handle[i] = -1;
	}

}


//�I������
void CSelectScene::Exit()
{
	eSceneID = SELECT_SCENE_INIT;
}


//���[�h
void CSelectScene::Load()
{
	m_startTime = GetNowCount();	// �N�����Ă���̎��Ԃ��擾
	m_handle[SELECT_IMAGE_CURSOR1] = LoadGraph("data/select/Cursor.png");
	m_handle[SELECT_IMAGE_CURSOR2] = LoadGraph("data/select/Cursor.png");
	m_handle[SELECT_IMAGE_CHARA1] = LoadGraph("data/select/�t���C�S��.png");

}


//�`��
void CSelectScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)m_alpha);

	//DrawBox(150, 0, 20, 500, COLOR, true, 0);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, (int)m_alpha);

	ImageBlink(m_handle[SELECT_IMAGE_CHARA1], &m_alpha2, 2, &m_BlinkFlag, 30, 5);

	//DrawBox(200, 0, 300, 500, COLOR, true, 0);

	if (m_alpha < 255)
		m_alpha++;
}


//���g�̏���
void CSelectScene::Step()
{
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = SELECT_SCENE_END;
	}

	CDebugString::GetInstance()->AddString(0, 0, "�Z���N�g�V�[��");
}


//���X�V
void CSelectScene::UpData()
{
}

void CSelectScene::ImageMove(float PositionX, float PositionY, int time, float Radius)
{

}

void CSelectScene::ImageChangeScale(int Handle, float Scale_Rate, float Scale_Speed)
{
	bool IsExpantion = true;	//�g��t���O

	DrawRotaGraph(120, 120, Scale_Rate, 0.0f, Handle, true);

	if (IsExpantion)
	{
		if (Scale_Rate <= 2.0f)
		{
			Scale_Rate += Scale_Speed;
		}
	}
}

void CSelectScene::ImageBlink(int Handle, float* p_Alpha, float BlinkSpeed, bool* p_BlinkFlag, float AddPace, float SubPace)
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

