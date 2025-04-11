#pragma once
#include "../Common.h"


//�v���C���[
constexpr float PLAYER_SPEED = 3.7f;			//�v���C���[���x
constexpr float PLAYER_SLOW_SPEED = 2.8f;		//�v���C���[���x

//�G�C��
constexpr float AIM_SPEED = 8.0f;				//�G�C���J�[�\���̈ړ����x
constexpr float AIM_RADIUS = 300.0f;			//�G�C���ƃv���C���[�̋���

//�v���C���[�̒e
constexpr int	 PLAYER_BULLET_MAX = 23;			//�v���C���[�e�ő吔
constexpr int	 PLAYER_BULLET_FIRE_TIME = 8;		//�v���C���[�e���ˉ\����
constexpr int	 PLAYER_BULLET_RELOAD_TIME = 150;	//�v���C���[�e���U���v����
constexpr float	 PLAYER_BULLET_SPEED = 10.0f;		//�v���C���[�e���x

//UI
constexpr int   PLAYER_UI_BULLET_X_1 = 100;		//1P�̒e���WX
constexpr int   PLAYER_UI_BULLET_X_2 = 740;		//2P�̒e���WX
constexpr int   PLAYER_UI_BULLET_Y = 48;		//�e���WY
constexpr int	PLAYER_UI_DISTA = 3;			//�eUI�̉��{��


//�v���C���[�N���X
class Player {
private:

	//�v���C���[
	int		imageHandle;			//�v���C���[�摜
	int		playerIndex;			//�v���C���[��P
	int		size;					//�v���C���[�T�C�Y
	VECTOR	pos;					//�v���C���[���W
	float	speed;					//�v���C���[���x
	float	rot;					//�v���C���[��]�l
	float	radian;					//�v���C���[�̈ړ�����
	
	//�G�C���֌W
	int aimHandle;
	VECTOR aimPos;			//�G�C���̍��W
	float aimRad;			//�G�C���̊p�x

	//�v���C���[�̒e
	int		 bulletHandle;						//�e�̉摜
	int		 bulletSize;						//�e�̃T�C�Y
	int		 bulletCount;						//�e�̎c�e��
	int		 bulletInterval;					//�e�̃C���^�[�o��
	int		 bulletReloadCount;					//�e�̑��U����
	VECTOR	 bulletPos[PLAYER_BULLET_MAX];		//�e�̍��W
	bool	 bulletReloadFlag;					//�e�̃����[�h�t���O
	bool	 bulletUseFlag[PLAYER_BULLET_MAX];	//�e�̎g�p�t���O
	float	 bulletRot[PLAYER_BULLET_MAX];		//�e�̉�]�l
	float	 bulletSpeed;						//�e�̑��x
	

public:

	Player();
	~Player(){};

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//�ʏ폈��
	void Step();

	//�`�揈��
	void Draw();

	//UI�̕`��
	void UiDraw();

	//�j������
	void Fin();

private:

	//�v���C���[�̈ړ�
	void PlayerMove();

	//�G�C������
	void Aim();

	//�e�̏���
	void Bullet();


public:

	//�v���C���[����P���Z�b�g
	void SetPlayerP(int player_p) { playerIndex = player_p; }
};