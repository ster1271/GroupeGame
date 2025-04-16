#include "SceneManager.h"


//�R���X�g���N�^
SceneManager::SceneManager()
{
	eSceneID = SCENE_TITLE;
}


//�f�X�g���N�^
SceneManager::~SceneManager()
{
}


//���[�v����
void SceneManager::Loop()
{
	switch (eSceneID)
	{
	case SCENE_TITLE:
		if (cTitleScene.Loop() != 0)
		{
			//�����Ń^�C�g���V�[�����폜

			eSceneID = SCENE_SELECT;
		}
		break;

	case SCENE_SELECT:
		if (cSelectScene.Loop() != 0)
		{
			//�����Ń^�C�g���V�[�����폜

			eSceneID = SCENE_PLAY;
		}
		break;

	case SCENE_PLAY:
		if (cPlayScene.Loop() != 0)
		{
			//�����Ńv���C�V�[�����폜

			eSceneID = SCENE_RESULT;
		}
		break;

	case SCENE_RESULT:
		if (cResultScene.Loop() != 0)
		{
			//�����Ń��U���g�V�[�����폜

			eSceneID = SCENE_TITLE;
		}
		break;

	case SCENE_NUM:

		break;

	default:
		break;
	}
}


//�`��
void SceneManager::Draw()
{
	switch (eSceneID)
	{
	case SCENE_TITLE:
		cTitleScene.Draw();
		break;

	case SCENE_SELECT:
		cSelectScene.Draw();
		break;

	case SCENE_PLAY:
		cPlayScene.Draw();
		break;

	case SCENE_RESULT:
		cResultScene.Draw();
		break;

	case SCENE_NUM:
		break;

	default:
		break;
	}
}
