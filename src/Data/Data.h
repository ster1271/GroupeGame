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

public:
	static void Create();				//�C���X�^���X�̐���
	static void Destroy();				//�C���X�^���X�̍폜
	static CData* GetInstance();		//�C���X�^���X�̎擾

	MAP_TYPE GetMapID() { return ID; }	//�I���}�b�v���̎擾
	void SetMapID(MAP_TYPE id) { ID = id; }
};
