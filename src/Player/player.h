#pragma once
#include "../Common.h"


//�v���C���[
constexpr int	PLAYER_MAX_HP = 100;					//�v���C���[�ő�HP
constexpr int	PLAYER_ATTACK_POWER[3] = { 2,5,15 };	//�v���C���[�U����
constexpr float PLAYER_SPEED = 3.7f;					//�v���C���[���x
constexpr float PLAYER_SLOW_SPEED = 2.5f;				//�v���C���[�G�C�������x

//�G�C��
constexpr float AIM_SPEED = 8.0f;						//�G�C���J�[�\���̈ړ����x
constexpr float AIM_RADIUS = 300.0f;					//�G�C���ƃv���C���[�̋���

//�v���C���[�̒e
constexpr int	 PLAYER_BULLET_MAX = 23;				//�v���C���[�e�ő吔
constexpr int	 PLAYER_BULLET_TIME[3] = { 6,10,50 };	//�v���C���[�e���ˉ\����
constexpr int	 PLAYER_BULLET_RELOAD_TIME = 150;		//�v���C���[�e���U���v����
constexpr float	 PLAYER_BULLET_SPEED = 10.0f;			//�v���C���[�e���x

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
	int		HP;						//�v���C���[�̗�
	int		def;					//�v���C���[�h���
	int		size;					//�v���C���[�T�C�Y
	int		attackPower;			//�v���C���[�U����
	VECTOR	pos;					//�v���C���[���W
	float	speed;					//�v���C���[���x
	float	rot;					//�v���C���[��]�l
	float	radian;					//�v���C���[�̈ړ�����
	
	//�G�C���֌W
	int aimHandle;			//�G�C���̉摜
	VECTOR aimPos;			//�G�C���̍��W
	float aimRad;			//�G�C���̊p�x

	//�v���C���[�̒e
	int		 bulletHandle;						//�e�̉摜
	int		 bulletSize;						//�e�̃T�C�Y
	int		 bulletCount;						//�e�̎c�e��
	int		 bulletInterval;					//�e�̃C���^�[�o���J�E���g
	int		 MaxBulletInterval;					//�e�̃C���^�[�o��
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

	//�v���C���[���W�擾
	VECTOR GetPos() { return pos; }

	//�v���C���[�{�b�N�X���W�擾
	VECTOR GetPos2() {
		VECTOR p;
		p.x = pos.x-16;
		p.y = pos.y - 16;
		p.z = 0;
		return p;
	}

	//�v���C���[�{�b�N�X���W�Z�b�g
	void SetPos2(VECTOR p_p) { 
		VECTOR p;
		p.x = p_p.x + 16;
		p.y = p_p.y + 16;
		p.z = 0;
		SetPos(p);
	}

	//�v���C���[�T�C�Y�擾
	int GetSize() { return 32; }

	//�v���C���[���W�Z�b�g
	void SetPos(VECTOR new_pos) { pos = new_pos; }

	//�v���C���[����P���Z�b�g
	void SetPlayerP(int player_p) { playerIndex = player_p; }

	//�v���C���[������Ԃ��擾
	bool GetAlive() {
		if (HP > 0) {
			return true;
		}
		return false;
	}

	//�e���W�擾
	VECTOR GetBulletPos(int index) { return bulletPos[index]; }

	//�e�g�p�t���O�𓾂�
	bool GetUse(int index) { return bulletUseFlag[index]; }

	//�e�g�p�t���O�܂�
	void SetUse(int index) { bulletUseFlag[index] = false; }

	//�v���C���[�U���͂𓾂�
	int GetAttackPower() { return attackPower; }

	//�_���[�W���󂯂�
	void Damage(int attack_power) { HP -= attack_power; }
};