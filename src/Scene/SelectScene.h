#pragma once
#include "../Common.h"

class CSelectScene
{
private:

	enum tagSELECT_SCENE
	{
		SELECT_SCENE_INIT,
		SELECT_SCENE_LAOD,
		SELECT_SCENE_LOOP,
		SELECT_SCENE_END,

		SELECT_SCENE_NUM
	};

	enum tagSELECT_IMAGE
	{
		SELECT_IMAGE_CURSOR1,
		SELECT_IMAGE_CURSOR2,
		SELECT_IMAGE_CHARA1,
		SELECT_IMAGE_CHARA2,
		SELECT_IMAGE_CHARA3,

		SELECT_IMAGE_NUM
	};

	struct Image
	{
		// ���W
		float PositionX;
		float PositionY;

		float Rotate;			// �p�x
		float Magnification;	// �g�嗦
		float Alpha;			// �A���t�@�l
		bool BlintFrag;			// �_�Ńt���O
		int Handle;				// �摜�n���h��
	};

	const Image e_Image[SELECT_IMAGE_NUM] =
	{
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0}
	};

	tagSELECT_SCENE eSceneID;

	int m_startTime;	// �p�\�R�����N�����Ă���̎���
	int m_NowTime;		// ���݂̎���
	int m_handle[SELECT_IMAGE_NUM];
	float m_alpha;
	float m_alpha2;
	bool m_BlinkFlag;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CSelectScene();
	~CSelectScene();

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

	void ImageMove(float PositionX, float PositionY, int time, float Radius);

	// ImageChangeScale �摜���g�k������
	// ==========�ϐ�==========
	// Handle		= �g�k���������摜�n���h��
	// Scale_Rate	= �摜�̑傫��
	// Scale_Speed	= �g�k�̑���
	void ImageChangeScale(int Handle, float Scale_Rate, float Scale_Speed);
};
