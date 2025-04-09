#include "ResultScene.h"


//�R���X�g���N�^
CResultScene::CResultScene()
{
	//�Ƃ肠�����������Ɉړ�������
	eSceneID = RESULT_SCENE_INIT;
}


//�f�X�g���N�^
CResultScene::~CResultScene()
{
	Exit();
}


//���[�v����
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


//������
void CResultScene::Init()
{
}


//�I������
void CResultScene::Exit()
{
	eSceneID = RESULT_SCENE_INIT;
}


//�f�[�^�ǂݍ���
void CResultScene::Load()
{
}

//�{�̏���
void CResultScene::Step()
{
	//�V�[���I������
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = RESULT_SCENE_END;
	}

	CDebugString::GetInstance()->AddString(0, 0, "���U���g�V�[��");
}

//�`��
void CResultScene::Draw()
{
	CDebugString::GetInstance()->Draw();
}
