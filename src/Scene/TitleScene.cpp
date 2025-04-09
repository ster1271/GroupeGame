#include "TitleScene.h"


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

	DrawBox(150, 0, 20, 500, COLOR, true, 0);
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

