#include "Map.h"

const char MAP_TIP_PATH01[128] = { "data/play/map/MapTip01.png" };
const char MAP_TIP_PATH02[128] = { "data/play/map/MapTip02.png" };

//�R���X�g���N�^
CMap::CMap()
{
	memset(&MapTipList, -1, sizeof(vector<MapTipInfo>));
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
	for (int Index = 0; Index < MAPTIP_TYPE_NUM; Index++)
	{

	}
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


//�}�b�v�̓ǂݍ���
bool CMap::LoadMap(MAP_TYPE id)
{

}