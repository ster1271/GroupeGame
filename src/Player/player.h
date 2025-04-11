#pragma once
#include "DxLib.h"


constexpr float PLAYER_SPEED = 3.0f;		//�v���C���[���x


//�v���C���[�N���X
class Player {
private:

	int playerIndex;		//�v���C���[��P
	int imageHandle;		//�v���C���[�摜
	VECTOR pos;				//�v���C���[���W
	int size;				//�v���C���[�T�C�Y
	float rot;				//�v���C���[��]�l
	float radian;			//�v���C���[�̈ړ�����

public:

	Player();
	~Player(){};

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//�ʏ폈��
	void Step();

	//�`�揈��
	void Draw();

	//�j������
	void Fin();


	//�v���C���[����P���Z�b�g
	void SetPlayerP(int player_p) { playerIndex = player_p; }
};