#include "ObjectBase.h"

//�R���X�g���N�^
CObjectBase::CObjectBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&MoveVec, 0, sizeof(VECTOR));
	MoveDis = 0.0f;

	iHndl = -1;
	IsActive = false;
}


//�f�X�g���N�^
CObjectBase::~CObjectBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&MoveVec, 0, sizeof(VECTOR));
	MoveDis = 0.0f;

	iHndl = -1;
	IsActive = false;
}


//������
void CObjectBase::Init()
{
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;
	MoveVec = VECTOR_ZERO;
	MoveDis = 0.0f;

	iHndl = -1;
	IsActive = false;
}


//�㏈��
void CObjectBase::Exit()
{
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;
	MoveVec = VECTOR_ZERO;
	MoveDis = 0.0f;

	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
		IsActive = false;
	}
}


//�ǂݍ��݊֘A
void CObjectBase::Load(int Hndl)
{
	//���f���̓ǂݍ���
	iHndl = MV1DuplicateModel(Hndl);

	Update();
}


//�`��
void CObjectBase::Draw()
{
	if (iHndl != -1)
	{
		//���f���̕`��
		MV1DrawModel(iHndl);
	}
}


//���t���[���s������
void CObjectBase::Step() {};


//�X�V����
void CObjectBase::Update()
{
	cPos = cNextPos;
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cScale);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}
