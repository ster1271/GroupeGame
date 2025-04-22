#include "ResultScene.h"

//#define CURSOR_NUMBER_NUM	(3)							// �J�[�\���̐�
//#define CURSOR_TITLE		(0)							// �^�C�g���J�[�\��
//#define CURSOR_SELECT		(1)							// �Z���N�g�J�[�\��
//#define CURSOR_PLAY			(2)							// �v���C�J�[�\��

#define PLAYER1WIN_HANDLE ("data/result/Player1Win.png")
#define PLAYER2WIN_HANDLE ("data/result/Player2Win.png")

//�R���X�g���N�^
CResultScene::CResultScene()
{
	//�Ƃ肠�����������Ɉړ�������
	eSceneID = RESULT_SCENE_INIT;
	m_WinFlag =false;
	m_CursorNumber = 0;
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

	m_WinFlag = false;
	m_CursorControl = false;
	m_CursorNumber = 0;
	Rappa = LoadSoundMem("data/result/���b�p�̃t�@���t�@�[��.mp3");
	ChangeVolumeSoundMem(255 * 60 / 100, Rappa);
	RappaFlag = false;

	Player1Win_Handle = LoadGraph(PLAYER1WIN_HANDLE);
	Player2Win_Handle = LoadGraph(PLAYER2WIN_HANDLE);

}


//�I������
void CResultScene::Exit()
{
	eSceneID = RESULT_SCENE_INIT;
	InitSoundMem();
}


//�f�[�^�ǂݍ���
void CResultScene::Load()
{

	m_WinFlag = CData::GetInstance()->GetPlayerWin();
	RappaFlag = true;

}

//�{�̏���
void CResultScene::Step()
{

	if (RappaFlag)
	{
		PlaySoundMem(Rappa, DX_PLAYTYPE_BACK, true);
		RappaFlag = false;
	}

	if (CInput::IsKeyPush(KEY_INPUT_DOWN) || PadInput::GetLY(0) > 100 && !m_CursorControl)
	{
		m_CursorNumber--;

		if (m_CursorNumber < 0)
		{
			m_CursorNumber = CURSOR_NUMBER_NUM - 1;
		}

		m_CursorControl = true;
	}

	else if (CInput::IsKeyPush(KEY_INPUT_UP) || PadInput::GetLY(0) < -100 && !m_CursorControl)
	{
		m_CursorNumber++;

		if (m_CursorNumber >= CURSOR_NUMBER_NUM)
		{
			m_CursorNumber = 0;
		}

		m_CursorControl = true;
	}

	else if (PadInput::GetLY(0) <= 10 && PadInput::GetLY(0) >= -10 && m_CursorControl)
	{
		m_CursorControl = false;
	}

	//�V�[���I������
	if (CInput::IsKeyPush(KEY_INPUT_RETURN) || PadInput::Push(0, XINPUT_BUTTON_A))
	{
		m_IsDecideScene = true;

		switch (m_CursorNumber)
		{
		case CURSOR_TITLE: e_SceneCuesor = CURSOR_TITLE;
			break;
		case CURSOR_SELECT: e_SceneCuesor = CURSOR_SELECT;
			break;
		case CURSOR_PLAY: e_SceneCuesor = CURSOR_PLAY;
			break;
		default:
			break;
		}
		eSceneID = RESULT_SCENE_END;
	}

	CDebugString::GetInstance()->AddString(0, 0, "���U���g�V�[��");
}

//�`��
void CResultScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	if (m_WinFlag)
	{
		DrawFormatString(0, 30, COLOR, "1P�̏����ł�");
		DrawGraph(0, 0, Player1Win_Handle, false);
	}
	else
	{
		DrawFormatString(0, 30, COLOR, "2P�̏����ł�");
		DrawGraph(0, 0, Player2Win_Handle, false);
	}

	switch (m_CursorNumber)
	{
	case CURSOR_TITLE: DrawFormatString(0, 45, COLOR, "�I�𒆁F�^�C�g��");
		break;
	case CURSOR_SELECT: DrawFormatString(0, 45, COLOR, "�I�𒆁F�Z���N�g");
		break;
	case CURSOR_PLAY: DrawFormatString(0, 45, COLOR, "�I�𒆁F�v���C�V�[��");
		break;
	default:
		break;
	}

}
