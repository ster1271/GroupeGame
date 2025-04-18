#pragma once
#include "../Common.h"
#include "../Data/Data.h"
#include "../Input/PadInput.h"

class CResultScene
{
public:
	enum SCENE_CURSOR
	{
		CURSOR_TITLE = 0,							// �^�C�g���J�[�\��
		CURSOR_SELECT,								// �Z���N�g�J�[�\��
		CURSOR_PLAY,								// �v���C�J�[�\��

		CURSOR_NUMBER_NUM							// �J�[�\���̐�
	};

private:
	enum tagRESULT_SCENE
	{
		RESULT_SCENE_INIT,
		RESULT_SCENE_LAOD,
		RESULT_SCENE_LOOP,
		RESULT_SCENE_END,

		RESULT_SCENE_NUM
	};

	tagRESULT_SCENE eSceneID;
	SCENE_CURSOR e_SceneCuesor;

	bool m_WinFlag;
	int m_CursorNumber;
	bool m_IsDecideScene;

	void SceneSelect();


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CResultScene();
	~CResultScene();

	//���[�v����
	int Loop();

	//������
	void Init();

	//�I������
	void Exit();

	//�f�[�^�ǂݍ���
	void Load();

	//�`��
	void Draw();

	//�{�̏���
	void Step();

	SCENE_CURSOR GetSceneCursor() { return e_SceneCuesor; }
};

