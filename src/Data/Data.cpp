#include "Data.h"

//�C���X�^���X�̏�����
CData* CData::cInstance = nullptr;

//�R���X�g���N�^�E�f�X�g���N�^
CData::CData() {};
CData::~CData() {};

//�C���X�^���X�̐���
void CData::Create()
{
	//�C���X�^���X�ɂ���������Ă��Ȃ�������
	if (cInstance == nullptr)
	{
		//�V����new����
		cInstance = new CData();
	}
}


//�C���X�^���X�̍폜
void CData::Destroy()
{
	//�C���X�^���X����������Ă�����
	if (cInstance != nullptr)
	{
		//delete����nullptr������
		delete cInstance;
		cInstance = nullptr;
	}
}


//�C���X�^���X�̎擾
CData* CData::GetInstance()
{
	if (cInstance == nullptr)
	{
		//�C���X�^���X����������Ă��Ȃ������琶������
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
}
