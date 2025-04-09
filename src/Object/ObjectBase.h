#pragma once
#include "../Common.h"

enum OBJECT_DIR
{
	OBJECT_DIR_UP,		//��
	OBJECT_DIR_DOWN,	//��
	OBJECT_DIR_LEFT,	//��
	OBJECT_DIR_RIGHT,	//�E

	OBJECT_DIR_NUM,		//���ԍ�
};

//�I�u�W�F�N�g�N���X
class CObjectBase
{
protected:
	VECTOR cPos;		//���W
	VECTOR cNextPos;	//1�t���[����̍��W
	VECTOR cRotate;		//��]�l
	VECTOR cSize;		//�T�C�Y(�c���A�����A���s)
	VECTOR cScale;		//�g��{��
	VECTOR MoveVec;		//�ړ��x�N�g��
	float MoveDis;		//�ړ���
	
	int iHndl;			//�n���h��

	bool IsActive;		//�t���O 

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CObjectBase();
	~CObjectBase();

	const VECTOR GetPos() { return cPos; }
	const VECTOR GetNextPos() { return cNextPos; }
	const VECTOR GetSize() { return cSize; }
	const VECTOR GetRotate() { return cRotate; }
	const VECTOR GetMoveVec() { return MoveVec; }

	void SetPos(VECTOR NewPos) { cPos = NewPos; }
	void SetRotate(VECTOR NewRotate) { cRotate = NewRotate; }


	//������
	void Init();

	//�㏈��
	void Exit();

	//�ǂݍ��݊֘A
	void Load(int Hndl);

	//�`��
	void Draw();

	//�{�̏���
	virtual void Step();

	//�X�V����
	void Update();



};
