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
	eSceneID = PLAY_SCENE_INIT;
}


//�f�[�^�ǂݍ���
void CPlayScene::Load()
{
	cMap.Load(MAP_TYPE_00);
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

	//���s���Z�b�g
	if (!player[0].GetAlive()) {
		CData::GetInstance()->SetPlayerWin(false);
	}
	if (!player[1].GetAlive()) {
		CData::GetInstance()->SetPlayerWin(true);
	}
}


//���X�V
void CPlayScene::UpData()
{
}
