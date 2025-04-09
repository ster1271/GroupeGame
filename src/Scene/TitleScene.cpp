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
}


//�I������
void CTitleScene::Exit()
{
	eSceneID = TITLE_SCENE_INIT;
}


//���[�h
void CTitleScene::Load()
{
}


//�`��
void CTitleScene::Draw()
{
	CDebugString::GetInstance()->Draw();
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

