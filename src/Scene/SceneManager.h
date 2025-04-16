#pragma once
#include "DxLib.h"
#include "PlayScene.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "ResultScene.h"

class SceneManager
{
private:
	enum tagSCENE
	{
		SCENE_TITLE,	//�^�C�g�����
		SCENE_SELECT,	//�I�����
		SCENE_PLAY,		//�Q�[����
		SCENE_RESULT,	//���U���g���

		SCENE_NUM
	};

	tagSCENE eSceneID;				//�V�[���ۑ�

	CTitleScene cTitleScene;		//�^�C�g���V�[��
	CSelectScene cSelectScene;		//�Z���N�g�V�[��
	CPlayScene cPlayScene;			//�v���C�V�[��
	CResultScene cResultScene;		//���U���g�V�[��

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	SceneManager();
	~SceneManager();

	//���[�v����
	void Loop();

	//�`��
	void Draw();

};