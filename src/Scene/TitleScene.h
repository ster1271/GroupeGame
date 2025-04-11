#pragma once
#include "../Common.h"

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
	float m_alpha;
	float m_alpha2;
	bool m_BlinkFlag;

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
	// p_Alpha		= ���̉摜�̃A���t�@�l������(&������)
	// BlinkSpeed	= �_�ő��x������
	// p_BlinkFlag  = �_�ł̃t���O(False�ŕs�����ɂȂ��Ă���)
	// AddPace		= �l�ɑ����قǕs�����ɂȂ�̂������Ȃ�
	// SubPace		= �l�������قǓ����ɂȂ�̂������Ȃ�
	void ImageBlink(float* p_Alpha, float BlinkSpeed, bool* p_BlinkFlag, float AddPace, float SubPace);

};
