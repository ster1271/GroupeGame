#include "SceneManager.h"


//コンストラクタ
SceneManager::SceneManager()
{
	eSceneID = SCENE_TITLE;
}


//デストラクタ
SceneManager::~SceneManager()
{
}


//ループ処理
void SceneManager::Loop()
{
	switch (eSceneID)
	{
	case SCENE_TITLE:
		if (cTitleScene.Loop() != 0)
		{
			//ここでタイトルシーンを削除

			eSceneID = SCENE_SELECT;
		}
		break;

	case SCENE_SELECT:
		if (cSelectScene.Loop() != 0)
		{
			//ここでタイトルシーンを削除

			eSceneID = SCENE_PLAY;
		}
		break;

	case SCENE_PLAY:
		if (cPlayScene.Loop() != 0)
		{
			//ここでプレイシーンを削除

			eSceneID = SCENE_RESULT;
		}
		break;

	case SCENE_RESULT:
		if (cResultScene.Loop() != 0)
		{
			//ここでリザルトシーンを削除

			eSceneID = SCENE_TITLE;
		}
		break;

	case SCENE_NUM:

		break;

	default:
		break;
	}
}


//描画
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
