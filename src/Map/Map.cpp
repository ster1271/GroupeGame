#include "Map.h"

const char MAP_TIP_PATH01[128] = { "data/play/map/MapTip01.png" };
const char MAP_TIP_PATH02[128] = { "data/play/map/MapTip02.png" };

//�R���X�g���N�^
CMap::CMap()
{
	memset(&cPos, -1, sizeof(VECTOR));
	memset(&cRotate, -1, sizeof(VECTOR));

	iHndl = -1;
}

//�f�X�g���N�^
CMap::~CMap()
{
	Exit();
}


//������
void CMap::Init()
{

}

//�㏈��
void CMap::Exit()
{

}

//�ǂݍ���
void CMap::Load()
{

}

//���X�V
void CMap::UpData()
{

}

//�{����
void CMap::Step()
{

}

//�`��
void CMap::Draw()
{

}