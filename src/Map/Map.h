#pragma once
#include "../Common.h"

const VECTOR MAP_TIP_SIZE = VGet(32.0f, 32.0f, 0.0f);

//�}�b�v�̎��
const enum MAP_TYPE
{
	MAP_TYPE_00,
	
	MAP_MAX_NUM,
};

const enum MAPTIP_TYPE
{
	MAPTIP_TYPE_00,
	MAPTIP_TYPE_01,

	MAPTIP_TYPE_NUM,
};

class CMap
{
private:
	FILE* fp;

	struct MapTipInfo
	{
		VECTOR cPos;
		VECTOR cRotate;
		VECTOR cSize;
		int iHndl;
	};

	vector<MapTipInfo> MapTipList;		//�}�b�v�`�b�v���i�[���X�g

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

	//�}�b�v�̓ǂݍ���
	bool LoadMap(MAP_TYPE id);
};
