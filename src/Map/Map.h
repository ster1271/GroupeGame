#pragma once
#include "../Common.h"

const VECTOR MAP_TIP_SIZE = VGet(32.0f, 32.0f, 0.0f);

class CMap
{
private:
	VECTOR cPos;
	VECTOR cRotate;
	VECTOR cSize;
	int iHndl;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CMap();
	~CMap();

	//������
	void Init();

	//�㏈��
	void Exit();

	//�ǂݍ���
	void Load();

	//���X�V
	void UpData();

	//�{����
	void Step();

	//�`��
	void Draw();
};
