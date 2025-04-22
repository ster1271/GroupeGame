#include "PlayScene.h"

//�R���X�g���N�^
CPlayScene::CPlayScene()
{
	//�ЂƂ܂��������ɂ��Ă���
	eSceneID = PLAY_SCENE_INIT;
}


//�f�X�g���N�^
CPlayScene::~CPlayScene()
{
	//�O�̈�
	Exit();
}

//���[�v����
int CPlayScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case PLAY_SCENE_INIT:
		Init();
		eSceneID = PLAY_SCENE_LAOD;
		break;

	case PLAY_SCENE_LAOD:
		Load();
		eSceneID = PLAY_SCENE_LOOP;
		break;

	case PLAY_SCENE_LOOP:
		Step();
		break;

	case PLAY_SCENE_END:
		Exit();
		eSceneID = PLAY_SCENE_INIT;
		iRet = 1;
		break;

	default:
		break;
	}

	return iRet;
}


//������
void CPlayScene::Init()
{	
	cMap.Init();
	for (int index = 0; index < 2; index++) {
		player[index].SetPlayerP(index);
		player[index].Init();
	}

}


//�I������
void CPlayScene::Exit()
{
	cMap.Exit();
	player[0].Fin();
	player[1].Fin();
	eSceneID = PLAY_SCENE_INIT;
}


//�f�[�^�ǂݍ���
void CPlayScene::Load()
{
	cMap.Load(CData::GetInstance()->GetMapID());
	for (int index = 0; index < 2; index++) {
		player[index].Load();
	}
}


//�`��
void CPlayScene::Draw()
{
	CDebugString::GetInstance()->Draw();
	cMap.Draw();
	for (int index = 0; index < 2; index++) {
		player[index].Draw();
	}
	for (int index = 0; index < 2; index++) {
		player[index].UiDraw();
	}
}


//�{�̏���
void CPlayScene::Step()
{
	//�V�[���I������
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = PLAY_SCENE_END;
	}

	for (int index = 0; index < 2; index++) {
		player[index].Step();
	}
	cCollisionManager.PlayerToPlayer(player);
	cCollisionManager.PlayerToBullet(player);
	cCollisionManager.BulletToMap(player, cMap);
	cCollisionManager.PlayerToMap(player,cMap);

	//���s���Z�b�g
	if (!player[0].GetAlive()) {
		CData::GetInstance()->SetPlayerWin(false);
		eSceneID = PLAY_SCENE_END;
	}
	if (!player[1].GetAlive()) {
		CData::GetInstance()->SetPlayerWin(true);
		eSceneID = PLAY_SCENE_END;
	}
}


//���X�V
void CPlayScene::UpData()
{
}
