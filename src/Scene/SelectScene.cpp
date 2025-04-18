#include "SelectScene.h"

#define ALPHA_MAX (255) // �A���t�@�l�̍ő�l

//�R���X�g���N�^
CSelectScene::CSelectScene()
{
	m_startTime = 0;
	m_NowTime = 0;
	m_Scene_index = 0;
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	m_ExpantionFlag = false;

	//UI
	for (int i = 0; i < SELECT_UI_IMAGE_NUM; i++)
	{
		m_UI_handle[i] = -1;
	}
	//1P��
	for (int i = 0; i < SELECT_CHARA_IMAGE_NUM; i++)
	{
		m_1PChara_handle[i] = -1;
		m_1PChara_index = -1;
		m_Is1PCharaSelected = false;
	}
	//2P��
	for (int i = 0; i < SELECT_CHARA_IMAGE_NUM; i++)
	{
		m_2PChara_handle[i] = -1;
		m_2PChara_index = -1;
		m_Is2PCharaSelected = false;
	}
	//�X�e�[�W
	for (int i = 0; i < SELECT_STAGE_IMAGE_NUM; i++)
	{
		m_Stage_handle[i] = -1;
		m_Stage_index = 0;
		m_IsStageSelected = false;
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
	m_Scene_index = SCREEN_CHARA;
	m_alpha = 0;
	m_alpha2 = 0;
	m_BlinkFlag = false;
	m_ExpantionFlag = true;

	//UI
	for (int i = 0; i < SELECT_UI_IMAGE_NUM; i++)
	{
		m_UI_handle[i] = -1;
	}
	//1P��
	for (int i = 0; i < SELECT_CHARA_IMAGE_NUM; i++)
	{
		m_1PChara_handle[i] = -1;
		m_1PChara_index = SELECT_CHARA_IMAGE_1;
		m_Is1PCharaSelected = false;
	}
	//2P��
	for (int i = 0; i < SELECT_CHARA_IMAGE_NUM; i++)
	{
		m_2PChara_handle[i] = -1;
		m_2PChara_index = SELECT_CHARA_IMAGE_1;
		m_Is2PCharaSelected = false;
	}
	//�X�e�[�W
	for (int i = 0; i < SELECT_STAGE_IMAGE_NUM; i++)
	{
		m_Stage_handle[i] = -1;
		m_Stage_index = SELECT_STAGE_IMAGE_1;
		m_IsStageSelected = false;
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
	
	//UI�摜
	m_UI_handle[SELECT_UI_IMAGE_CURSOR1] = LoadGraph("data/select/Cursor.png");
	m_UI_handle[SELECT_UI_IMAGE_CURSOR2] = LoadGraph("data/select/Cursor.png");
	m_UI_handle[SELECT_UI_IMAGE_CURSOR3] = LoadGraph("data/select/Cursor.png");
	m_UI_handle[SELECT_UI_IMAGE_CURSOR4] = LoadGraph("data/select/Cursor.png");
	
	//�L�����N�^�[�摜
	//1P��
	m_1PChara_handle[SELECT_CHARA_IMAGE_1] = LoadGraph("data/select/�t���C�S��.png");
	m_1PChara_handle[SELECT_CHARA_IMAGE_2] = LoadGraph("data/select/�z�C�[�K.png");
	m_1PChara_handle[SELECT_CHARA_IMAGE_3] = LoadGraph("data/select/Cursor.png");
	//2P��
	m_2PChara_handle[SELECT_CHARA_IMAGE_1] = LoadGraph("data/select/�t���C�S��.png");
	m_2PChara_handle[SELECT_CHARA_IMAGE_2] = LoadGraph("data/select/�z�C�[�K.png");
	m_2PChara_handle[SELECT_CHARA_IMAGE_3] = LoadGraph("data/select/Cursor.png");

	//�X�e�[�W�摜
	m_Stage_handle[SELECT_STAGE_IMAGE_1] = LoadGraph("data/select/�t���C�S��.png");
	m_Stage_handle[SELECT_STAGE_IMAGE_2] = LoadGraph("data/select/�z�C�[�K.png");
	m_Stage_handle[SELECT_STAGE_IMAGE_3] = LoadGraph("data/select/Cursor.png");
}


//�`��
void CSelectScene::Draw()
{
	CDebugString::GetInstance()->Draw();

	SetFontSize(48);

	//�w�i(��)
	DrawBox(0, 0, 1280, 720, GetColor(0, 0, 255), true);

	if (m_Scene_index == SCREEN_CHARA)
	{
		//�����̋�؂�̐�
		DrawBox(0, 345, 1280, 375, GetColor(0, 0, 0), true);

		if (!m_Is1PCharaSelected)
		{
			DrawRotaGraph(250, 172.5f, 1.0f, 0.0f, m_UI_handle[SELECT_UI_IMAGE_CURSOR1], true, true);
			DrawRotaGraph(1030, 172.5f, 1.0f, 0.0f, m_UI_handle[SELECT_UI_IMAGE_CURSOR2], true, false);
		}
		if (!m_Is2PCharaSelected)
		{
			DrawRotaGraph(250, 532.5f, 1.0f, 0.0f, m_UI_handle[SELECT_UI_IMAGE_CURSOR3], true, true);
			DrawRotaGraph(1030, 532.5f, 1.0f, 0.0f, m_UI_handle[SELECT_UI_IMAGE_CURSOR4], true, false);
		}

		//1P
		DrawRotaGraph(640, 172.5f, 0.75f, 0.0f, m_1PChara_handle[m_1PChara_index], true);
		//2P
		DrawRotaGraph(640, 532.5f, 0.75f, 0.0f, m_2PChara_handle[m_2PChara_index], true);

		DrawString(0, 0, "�L�����N�^�[�Z���N�g", GetColor(255, 255, 255));
	}
	else if (m_Scene_index == SCREEN_STAGE)
	{
		DrawRotaGraph(200, 360, 1.5f, 0.0f, m_UI_handle[SELECT_UI_IMAGE_CURSOR1], true, true);
		DrawRotaGraph(1080, 360, 1.5f, 0.0f, m_UI_handle[SELECT_UI_IMAGE_CURSOR2], true, false);
		DrawRotaGraph(640, 360, 1.0f, 0.0f, m_Stage_handle[m_Stage_index], true);
		DrawString(0, 0, "�X�e�[�W�Z���N�g", GetColor(255, 255, 255));
		DrawString(0, 50, "��1P������", GetColor(255, 255, 255));
	}
}


//���g�̏���
void CSelectScene::Step()
{
	if (m_Scene_index == SCREEN_CHARA)
	{
		//�L�����N�^�[�摜�I��
		ChangeCharaImage();
		//�L�����N�^�[����
		SelectChara();
		//�L�����N�^�[�L�����Z��
		CancelChara();
	}
	else if(m_Scene_index == SCREEN_STAGE)
	{
		//�X�e�[�W�I��
		ChangeStageImage();
		//�X�e�[�W����
		SelectStage();
	}

	//�L�����N�^�[�I�����X�e�[�W�I��
	if (m_Is1PCharaSelected && m_Is2PCharaSelected)
	{
		m_Scene_index = SCREEN_STAGE;
	}
	
	if (m_Scene_index == SCREEN_STAGE)
	{
		if (PadInput::Push(0, XINPUT_BUTTON_A))
		{
			eSceneID = SELECT_SCENE_END;
		}
	}

	CDebugString::GetInstance()->AddString(0, 0, "�Z���N�g�V�[��");
}

//���X�V
void CSelectScene::UpData()
{

}

//�L�����N�^�[�I��
void CSelectScene::ChangeCharaImage()
{
	if (!m_Is1PCharaSelected)
	{
		//1P��
		//�X�e�B�b�N���E��
		if (PadInput::GetPushLX(0) > 0)
		{
			if (m_1PChara_index == SELECT_CHARA_IMAGE_3)
			{
				m_1PChara_index = SELECT_CHARA_IMAGE_1;
			}
			else
			{
				m_1PChara_index++;
			}
		}
		//�X�e�B�b�N������
		else if (PadInput::GetPushLX(0) < 0)
		{
			if (m_1PChara_index == SELECT_CHARA_IMAGE_1)
			{
				m_1PChara_index = SELECT_CHARA_IMAGE_3;
			}
			else
			{
				m_1PChara_index--;
			}
		}
	}
	
	if (!m_Is2PCharaSelected)
	{
		//2P��
		//�X�e�B�b�N���E��
		if (PadInput::GetPushLX(1) > 0)
		{
			if (m_2PChara_index == SELECT_CHARA_IMAGE_3)
			{
				m_2PChara_index = SELECT_CHARA_IMAGE_1;
			}
			else
			{
				m_2PChara_index++;
			}
		}
		//�X�e�B�b�N������
		else if (PadInput::GetPushLX(1) < 0)
		{
			if (m_2PChara_index == SELECT_CHARA_IMAGE_1)
			{
				m_2PChara_index = SELECT_CHARA_IMAGE_3;
			}
			else
			{
				m_2PChara_index--;
			}
		}
	}
}

//�L�����N�^�[����
void CSelectScene::SelectChara()
{
	if (!m_Is1PCharaSelected)
	{
		//1P��
		if (PadInput::Push(0, XINPUT_BUTTON_A))
		{
			switch (m_1PChara_index)
			{
				case SELECT_CHARA_IMAGE_1:
					CData::GetInstance()->SetPlayerType(0, 0);
					break;
				case SELECT_CHARA_IMAGE_2:
					CData::GetInstance()->SetPlayerType(0, 1);
					break;
				case SELECT_CHARA_IMAGE_3:
					CData::GetInstance()->SetPlayerType(0, 2);
					break;
			}
						
			m_Is1PCharaSelected = true;
		}
	}
	
	if (!m_Is2PCharaSelected)
	{
		//2P��
		if (PadInput::Push(1, XINPUT_BUTTON_A))
		{
			switch (m_2PChara_index)
			{
				case SELECT_CHARA_IMAGE_1:
					CData::GetInstance()->SetPlayerType(1, 0);
					break;
				case SELECT_CHARA_IMAGE_2:
					CData::GetInstance()->SetPlayerType(1, 1);
					break;
				case SELECT_CHARA_IMAGE_3:
					CData::GetInstance()->SetPlayerType(1, 2);
					break;
			}

			m_Is2PCharaSelected = true;
		}
	}
}

//�L�����N�^�[�L�����Z��
void CSelectScene::CancelChara()
{
	if (m_Is1PCharaSelected)
	{
		//1P��
		if (PadInput::Push(0, XINPUT_BUTTON_B))
		{
			m_Is1PCharaSelected = false;
		}
	}
	
	if (m_Is2PCharaSelected)
	{
		//2P��
		if (PadInput::Push(1, XINPUT_BUTTON_B))
		{
			m_Is2PCharaSelected = false;
		}
	}
}

//�X�e�[�W�I��
void CSelectScene::ChangeStageImage()
{
	//1P������
	//�X�e�B�b�N���E��
	if (PadInput::GetPushLX(0) > 0)
	{
		if (m_Stage_index == SELECT_STAGE_IMAGE_3)
		{
			m_Stage_index = SELECT_STAGE_IMAGE_1;
		}
		else
		{
			m_Stage_index++;
		}
	}
	//�X�e�B�b�N������
	else if (PadInput::GetPushLX(0) < 0)
	{
		if (m_Stage_index == SELECT_STAGE_IMAGE_1)
		{
			m_Stage_index = SELECT_STAGE_IMAGE_3;
		}
		else
		{
			m_Stage_index--;
		}
	}
}

//�X�e�[�W����
void CSelectScene::SelectStage()
{
	//1P������
	if (!m_IsStageSelected)
	{
		if (PadInput::Push(0, XINPUT_BUTTON_A))
		{
			switch (m_Stage_index)
			{
				case SELECT_STAGE_IMAGE_1:
					CData::GetInstance()->SetMapID(MAP_TYPE_00);
					break;
				case SELECT_STAGE_IMAGE_2:
					CData::GetInstance()->SetMapID(MAP_TYPE_01);
					break;
				case SELECT_STAGE_IMAGE_3:
					CData::GetInstance()->SetMapID(MAP_TYPE_02);
					break;
			}
			
			m_Is1PCharaSelected = true;
		}
	}	
}

//�X�e�[�W�L�����Z��
void CSelectScene::CancelStage()
{
	//1P������
	if (m_IsStageSelected)
	{
		if (PadInput::Push(0, XINPUT_BUTTON_B))
		{
			m_Is1PCharaSelected = false;
			m_Scene_index = SCREEN_STAGE;
		}
	}
}

void CSelectScene::ImageMove(float PositionX, float PositionY, int time, float Radius)
{

}

void CSelectScene::ImageBlink(int Handle, float* p_Alpha, float BlinkSpeed, bool* p_BlinkFlag, float AddPace, float SubPace)
{

	float Alpha = *p_Alpha;
	float BlinkFlag = *p_BlinkFlag;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)Alpha);
	for (int i = 0; i < PLAYER_NUM; i++)
	{
		DrawRotaGraph(640, 172.5f, 0.75f, 0.0f, Handle, true);
		DrawRotaGraph(640, 172.5f, 0.75f, 0.0f, m_1PChara_handle[m_1PChara_index], true);
		DrawRotaGraph(640, 532.5f, 0.75f, 0.0f, m_2PChara_handle[m_2PChara_index], true);
	}	
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

		if (Alpha <= ALPHA_MAX / 4)
		{
			Alpha = ALPHA_MAX / 4;
			BlinkFlag = false;

		}
	}

	*p_Alpha = Alpha;
	*p_BlinkFlag = BlinkFlag;

}

