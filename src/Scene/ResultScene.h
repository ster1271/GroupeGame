#pragma once
#include "../Common.h"

class CResultScene
{
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
};

