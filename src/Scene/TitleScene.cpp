#include "TitleScene.h"

#define ALPHA_MAX (255) // �A���t�@�l�̍ő�l

//�R���X�g���N�^
CTitleScene::CTitleScene()
{
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
}


//�`��
void CTitleScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA,m_alpha);

	DrawBox(150, 0, 20, 500, COLOR, true, 0);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, m_alpha);

	ImageBlink(&m_alpha2,2,&m_BlinkFlag,30,5);


	DrawBox(200, 0, 300, 500, COLOR, true, 0);

	if(m_alpha < 255)
	m_alpha++;
}


//���g�̏���
void CTitleScene::Step()
{
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

void CTitleScene::ImageBlink(float *p_Alpha, float BlinkSpeed, bool *p_BlinkFlag ,float AddPace,float SubPace)
{

	int Alpha = *p_Alpha;
	int BlinkFlag = *p_BlinkFlag;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)Alpha);
	DrawBox(350, 0, 500, 500, COLOR, true, 0);
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

