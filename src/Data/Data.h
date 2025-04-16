#pragma once
#include "../Map/Map.h"

class CData
{
private:
	//�R���X�g���N�^�E�f�X�g���N�^
	CData();
	~CData();

	static CData* cInstance;		//�C���X�^���X

	MAP_TYPE ID;

	int playerType[2];				//�v���C���[�^�C�v(2�l��)
	
	bool playerWin;					//�v���C���[�̏��s�t���Otrue�̓v���C���[�P�̏����Afalse�̓v���C���[�Q�̏���

public:
	static void Create();				//�C���X�^���X�̐���
	static void Destroy();				//�C���X�^���X�̍폜
	static CData* GetInstance();		//�C���X�^���X�̎擾

	MAP_TYPE GetMapID() { return ID; }	//�I���}�b�v���̎擾
	void SetMapID(MAP_TYPE id) { ID = id; }

	//�v���C���[�̃^�C�v���Z�b�g�B�����P�A0�`1�v���C���[�̔ԍ��A�����Q�A�I�����ꂽ�v���C���[�^�C�v
	void SetPlayerType(int player_p, int player_type) {
		playerType[player_p] = player_type;
	}

	int GetPlayerType(int player_p) { return playerType[player_p]; }
	
	void SetPlayerWin(bool a) { playerWin = a; };

	//�v���C���[�̏�����Ԃ��擾(true�̓v���C���[�P�̏����Afalse�̓v���C���[�Q�̏���)
	bool GetPlayerWin() { return playerWin; };
};
