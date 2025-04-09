#pragma once
#include "../Common.h"

class CTitleScene
{
private:
	enum tagTITLE_SCENE
	{
		TITLE_SCENE_INIT,
		TITLE_SCENE_LAOD,
		TITLE_SCENE_LOOP,
		TITLE_SCENE_END,

		TITLE_SCENE_NUM
	};

	tagTITLE_SCENE eSceneID;

	int m_startTime;	// �N�����Ă���̎���
	int m_NowTime;		// ���݂̎���

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTitleScene();
	~CTitleScene();

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

	//���X�V
	void UpData();
};
