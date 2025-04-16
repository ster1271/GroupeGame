#pragma once
#include "../Common.h"
#include "../Map/Map.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Data/Data.h"

//�v���C�V�[���N���X
class CPlayScene
{
private:
	enum tagPLAY_SCENE
	{
		PLAY_SCENE_INIT,
		PLAY_SCENE_LAOD,
		PLAY_SCENE_LOOP,
		PLAY_SCENE_END,

		PLAY_SCENE_NUM
	};

	
	tagPLAY_SCENE eSceneID;

	Player player[2];
	CMap cMap;
	CCollisionManager cCollisionManager;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayScene();
	~CPlayScene();

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
