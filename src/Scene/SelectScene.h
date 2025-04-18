#pragma once
#include "../Common.h"
#include "../Data/Data.h"
#include "../Input/Input.h"
#include "../Input/PadInput.h"

const int PLAYER_NUM = 2;

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

	enum tagSELECT_UI_IMAGE
	{
		SELECT_UI_IMAGE_CURSOR1,
		SELECT_UI_IMAGE_CURSOR2,
		SELECT_UI_IMAGE_CURSOR3,
		SELECT_UI_IMAGE_CURSOR4,
		SELECT_UI_IMAGE_TEXT1,
		SELECT_UI_IMAGE_TEXT2,
		SELECT_UI_IMAGE_TEXT3,
		SELECT_UI_IMAGE_TEXT4,
		SELECT_UI_IMAGE_TEXT5,

		SELECT_UI_IMAGE_NUM
	};

	enum tagSELECT_CHARA_IMAGE
	{
		SELECT_CHARA_IMAGE_1,
		SELECT_CHARA_IMAGE_2,
		SELECT_CHARA_IMAGE_3,

		SELECT_CHARA_IMAGE_NUM
	};

	enum tagSELECT_STAGE_IMAGE
	{
		SELECT_STAGE_IMAGE_1,
		SELECT_STAGE_IMAGE_2,
		SELECT_STAGE_IMAGE_3,

		SELECT_STAGE_IMAGE_NUM
	};

	enum tagSCREEN
	{
		SCREEN_CHARA,
		SCREEN_STAGE,

		SCREEN_NUM
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

	tagSELECT_SCENE eSceneID;

	int m_startTime;	// �p�\�R�����N�����Ă���̎���
	int m_NowTime;		// ���݂̎���
	int m_UI_handle[SELECT_UI_IMAGE_NUM];

	int m_1PChara_handle[SELECT_CHARA_IMAGE_NUM];	//1P�L�����N�^�[�摜
	int m_1PChara_index;		//1P�L�����N�^�[�摜�̓Y����
	bool m_Is1PCharaSelected;	//1P�L�����N�^�[���蔻�f�p

	int m_2PChara_handle[SELECT_CHARA_IMAGE_NUM];	//2P�L�����N�^�[�摜
	int m_2PChara_index;		//2P�L�����N�^�[�摜�̓Y����
	bool m_Is2PCharaSelected;	//2P�L�����N�^�[���蔻�f�p

	int m_Stage_handle[SELECT_STAGE_IMAGE_NUM];
	int m_Stage_index;
	bool m_IsStageSelected;

	int m_Scene_index;
	float m_alpha;
	float m_alpha2;
	bool m_BlinkFlag;
	bool m_ExpantionFlag;	//�g��t���O

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

	//�L�����N�^�[�I��
	void ChangeCharaImage();
	//�L�����N�^�[����
	void SelectChara();
	//�L�����N�^�[�L�����Z��
	void CancelChara();

	//�X�e�[�W�I��
	void ChangeStageImage();
	//�X�e�[�W����
	void SelectStage();
	//�X�e�[�W�L�����Z��
	void CancelStage();

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
};
