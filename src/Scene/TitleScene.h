#pragma once
#include "../Common.h"
#include "../Input/PadInput.h"

class CTitleScene
{
private:

	enum tagTITLE_SCENE
	{
		TITLE_SCENE_INIT,
		TITLE_SCENE_LAOD,
		TITLE_SCENE_LOOP,
		TITLE_SCENE_END,

		TITLE_SCENE_NUM
	};

	//struct Image
	//{
	//	// ���W
	//	float PositionX;
	//	float PositionY;

	//	float Rotate;			// �p�x
	//	float Magnification;	// �g�嗦
	//	float Alpha;			// �A���t�@�l
	//	bool BlintFrag;			// �_�Ńt���O
	//	int Handle;				// �摜�n���h��

	//};

	/*const Image e_Image[4] =
	{
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0}
	};*/

	tagTITLE_SCENE eSceneID;

	int m_startTime;	// �p�\�R�����N�����Ă���̎���
	int m_NowTime;		// ���݂̎���
	int m_handle;
	int m_SelectPointer;
	int m_ArrivalTime;	// �摜�̓��B����
	int m_PlayerIndex[2];
	float m_alpha;
	
	bool m_BlinkFlag;

	// �f�o�b�N�p�̕ϐ�
	float m_PosX;
	float m_PosY;
	float m_StartPosX;
	float m_StartPosY;
	float m_alpha2;
	float m_TwoPointDistance;	// ��_�Ԃ̋���
	float m_TwoPointRadius;		// ��_�Ԃ̊p�x
	int m_HoiigaHandle;
	float Angle;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTitleScene();
	~CTitleScene();

	//���[�v����
	int Loop();

	//������
	void Init();

	//�I������
	void Exit();

	//�f�[�^�ǂݍ���
	void Load();

	//�`��
	void Draw();

	//�{�̏���
	void Step();

	//���X�V
	void UpData();

private:

	// �`��֐�

	// ImageBlink �摜��_�ł�����
	// ==========�ϐ�==========
	// Handle		= �_�ł��������摜�n���h��
	// p_Alpha		= ���̉摜�̃A���t�@�l������(&������)
	// BlinkSpeed	= �_�ő��x������
	// p_BlinkFlag	= �_�ł̃t���O(False�œ����ɂȂ��Ă���)
	// AddPace		= �l�ɑ����قǕs�����ɂȂ�̂������Ȃ�
	// SubPace		= �l�������قǓ����ɂȂ�̂������Ȃ�
	void ImageBlink(int Handle, float* p_Alpha, float BlinkSpeed, bool* p_BlinkFlag, float AddPace, float SubPace);

	void ImageMove(float StartPositionX, float StartPositionY, float EndPositionX, float EndPositionY,
					float MoveSpeed,int time, float* p_MovePositionX, float* p_MovePositionY);

};
