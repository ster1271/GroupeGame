#include "player.h"
#include "../Input/PadInput.h"
#include "math.h"
#include "../Data/Data.h"

#define DEG_TO_RAD(a)	((a) * DX_PI_F / 180.0f)	// ���W�A���p�ɕϊ����鎮

//�v���C���[�R���X�g���N�^
Player::Player() {

	HP = -1;
	speed = -1.0f;
	playerIndex = -1;
	imageHandle=-1;
	memset(&pos,0,sizeof(VECTOR));
	size = -1;
	rot = -1.0f;
	radian = -1.0f;

	aimHandle = -1;
	memset(&aimPos, 0, sizeof(VECTOR));
	aimRad = -1;

	bulletHandle = -1;
	bulletCount = -1;
	bulletReloadCount = -1;
	bulletSize = -1;
	bulletInterval = -1;
	memset(&bulletPos,0,sizeof(VECTOR[PLAYER_BULLET_MAX]));
	bulletReloadFlag = 0;
	memset(&bulletUseFlag,0,sizeof(bool[PLAYER_BULLET_MAX]));
	memset(&bulletRot, 0, sizeof(float[PLAYER_BULLET_MAX]));
	bulletSpeed = -1;
}


//�v���C���[������
void Player::Init() {
	
	HP = PLAYER_MAX_HP;
	bulletSpeed = PLAYER_BULLET_SPEED;
	bulletCount = PLAYER_BULLET_MAX;
	bulletReloadCount = 0;
	if (playerIndex == 1) {
		pos.x = 100;
	}
	maxSpeed= PLAYER_SPEED[CData::GetInstance()->GetPlayerType(playerIndex)];
	attackPower = PLAYER_ATTACK_POWER[CData::GetInstance()->GetPlayerType(playerIndex)];
	MaxBulletInterval= PLAYER_BULLET_TIME[CData::GetInstance()->GetPlayerType(playerIndex)];
}


//�v���C���[�ǂݍ���
void Player::Load() {
	aimHandle = LoadGraph("data/play/player/aim.png");
	bulletHandle = LoadGraph("data/play/player/bullet.png");
	if (playerIndex == 0) {
		imageHandle = LoadGraph("data/play/player/player1.png");
		bgm = LoadSoundMem("data/play/player/p_bgm.mp3");
		ChangeVolumeSoundMem(255 * 60/100, bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, true);
		soundHandle[0] = LoadSoundMem("data/play/player/shot1.mp3");
		soundHandle[1] = LoadSoundMem("data/play/player/damage1.mp3");
	}
	else {
		imageHandle = LoadGraph("data/play/player/player2.png");
		soundHandle[0] = LoadSoundMem("data/play/player/shot2.mp3");
		soundHandle[1] = LoadSoundMem("data/play/player/damage2.mp3");
	}
	if (playerIndex == 0) {
			pos.x = 100;
		}
		else {
			pos.x = 1180;
		}
		pos.y = SCREEN_SIZE_Y / 2+30;
}


//�v���C���[�ʏ폈��
void Player::Step() {

	//�v���C���[�ړ�
	PlayerMove();

	//�G�C������
	Aim();

	//�e�̏���
	Bullet();

	//�Œ���̐���
	if (HP < 0) {
		HP = 0;
	}
	if (pos.x <= 16.0f) {
		pos.x = 16.0f;
	}
	if (pos.x >= 1264.0f) {
		pos.x = 1264.0f;
	}
	if (pos.y <= 105.0f) {
		pos.y = 105.0f;
	}
	if (pos.y >= 704.0f) {
		pos.y = 704.0f;
	}

	if (aimPos.x <= 16.0f) {
		aimPos.x = 16.0f;
	}
	if (aimPos.x >= 1264.0f) {
		aimPos.x = 1264.0f;
	}
	if (aimPos.y <= 105.0f) {
		aimPos.y = 105.0f;
	}
	if (aimPos.y >= 704.0f) {
		aimPos.y = 704.0f;
	}
}


//�v���C���[�`��
void Player::Draw() {
	DrawCircle((int)pos.x, (int)pos.y, 16, GetColor(255, 255, 255));
	DrawLine((int)pos.x, (int)pos.y, (int)(pos.x + 50.0f * cosf(rot)), (int)(pos.y - 50.0f * sinf(rot)), GetColor(255, 0, 0), 4);
	DrawRotaGraph((int)pos.x, (int)pos.y,1.0,0.0,imageHandle,true);
	

	//�e�̕`��
	for (int index = 0; index < PLAYER_BULLET_MAX; index++) {
		if (!bulletUseFlag[index]) { continue; }
		DrawRotaGraph((int)bulletPos[index].x, (int)bulletPos[index].y, 1.0, -bulletRot[index]+ DEG_TO_RAD(90), bulletHandle, true);
	}
}



//UI�̕`��
void Player::UiDraw() {

	//�G�C��UI
	if (PadInput::Keep(playerIndex, XINPUT_BUTTON_LEFT_SHOULDER)) {
		DrawRotaGraph((int)aimPos.x, (int)aimPos.y, 1.0, 0.0, aimHandle, true);
	}

	int num;

	if (playerIndex == 0) {
		num = PLAYER_UI_BULLET_X_1;
		DrawBox(0, 0, SCREEN_SIZE_X / 2, 90, GetColor(255, 150, 150), true);
		//HP
		DrawBox(570, 8, 570 - PLAYER_MAX_HP * 5, 42, GetColor(0, 0, 0), true);
		DrawBox(570, 8, 570 - HP * 5, 42, GetColor(0, 255, 0), true);
	}
	else {
		num = PLAYER_UI_BULLET_X_2;
		DrawBox(SCREEN_SIZE_X / 2, 0, SCREEN_SIZE_X, 90, GetColor(150, 150, 225), true);
		//HP
		DrawBox(1210, 8, 1210 - PLAYER_MAX_HP * 5, 42, GetColor(0, 0, 0), true);
		DrawBox(1210, 8, 1210 - HP * 5, 42, GetColor(0, 255, 0), true);
	}

	//�����[�hUI
	if (bulletReloadFlag) {
		DrawBox((num+PLAYER_BULLET_RELOAD_TIME * PLAYER_UI_DISTA)+20, PLAYER_UI_BULLET_Y, 10+num + (PLAYER_BULLET_RELOAD_TIME- bulletReloadCount)* PLAYER_UI_DISTA, PLAYER_UI_BULLET_Y + 40, GetColor(255, 255, 0), true);
	}
	else {//�c�e�\��
		int pos_x = 0, pos_y = 0;
		for (int index = 0; index < bulletCount; index++) {
			pos_x = num + PLAYER_BULLET_RELOAD_TIME * PLAYER_UI_DISTA;
			pos_x -= index * 20;
			pos_y = PLAYER_UI_BULLET_Y;
			DrawGraph(pos_x, pos_y, bulletHandle, true);
		}	
	}

	//�g�\��
	int pos_x = 0, pos_y = 0;
	for (int index = 0; index < PLAYER_BULLET_MAX; index++) {
		pos_x = num + PLAYER_BULLET_RELOAD_TIME * PLAYER_UI_DISTA;
		pos_x -= index * 20;
		pos_y = PLAYER_UI_BULLET_Y;
		DrawBox(pos_x, pos_y, pos_x + 20, pos_y + 40, 0, false);
	}
}


//�v���C���[�j��
void Player::Fin() {
	StopSoundMem(bgm);
	InitSoundMem();
	for (int index = 0;index < PLAYER_BULLET_MAX;index++) {
		bulletUseFlag[index] = false;
	}
}


//�v���C���[�̈ړ�
void Player::PlayerMove() {

	prePos = pos;

	//�ړ����͂���Ă�������s
	if (PadInput::GetLX(playerIndex) != 0 || PadInput::GetLY(playerIndex) != 0) {

		//���͂��ꂽ�ړ��p�x�����߂�
		radian = atan2f((float)PadInput::GetLY(playerIndex), (float)PadInput::GetLX(playerIndex));

		//�G�C���{�^����������Ă�����ړ����x��ύX
		if (PadInput::Keep(playerIndex, XINPUT_BUTTON_LEFT_SHOULDER)) {
			speed = PLAYER_SLOW_SPEED[CData::GetInstance()->GetPlayerType(playerIndex)];
		}
		else {
			speed = maxSpeed;
			rot = radian;
		}

		//���W�̍X�V
		pos.x = pos.x + speed * cosf(radian);
		pos.y = pos.y - speed * sinf(radian);
	}
}


//�G�C������
void Player::Aim() {


	//�G�C���{�^���������ꂽ����s
	if (PadInput::Push(playerIndex, XINPUT_BUTTON_LEFT_SHOULDER)) {

		aimPos.x = pos.x + AIM_RADIUS * cosf(rot);
		aimPos.y = pos.y - AIM_RADIUS * sinf(rot);
		aimRad = atan2f(aimPos.y - pos.y, aimPos.x - pos.x);
	}

	if (PadInput::Keep(playerIndex, XINPUT_BUTTON_LEFT_SHOULDER)) {

		//�ړ����͂���Ă�������s
		if (PadInput::GetRX(playerIndex) != 0 || PadInput::GetRY(playerIndex) != 0) {

			//���͂��ꂽ�ړ��p�x�����߂�
			aimRad = atan2f((float)PadInput::GetRY(playerIndex), (float)PadInput::GetRX(playerIndex));
			aimPos.x = aimPos.x + AIM_SPEED * cosf(aimRad);
			aimPos.y = aimPos.y - AIM_SPEED * sinf(aimRad);
		}
		aimRad = atan2f(pos.y - aimPos.y, aimPos.x - pos.x);
		rot = aimRad;
	}
}


//�e�̏���
void Player::Bullet() {

	//�C���^�[�o�����J�E���g
	bulletInterval++;

	//�e�����ˉ\�Ȃ���s
	if (bulletInterval > MaxBulletInterval && bulletCount > 0) {
		if (PadInput::Keep(playerIndex,XINPUT_BUTTON_RIGHT_SHOULDER)&& !bulletReloadFlag) {
			bulletInterval = 0;
			//�e�𔭎�
			for (int index = 0; index < PLAYER_BULLET_MAX; index++) {
				if (bulletUseFlag[index]) { continue; }
				PlaySoundMem(soundHandle[0], DX_PLAYTYPE_BACK, true);
				bulletPos[index] = pos;
				bulletRot[index] = rot;
				bulletUseFlag[index] = true;
				bulletCount--;
				break;
			}
		}
	}

	//�e�̈ړ�
	for (int index = 0; index < PLAYER_BULLET_MAX; index++) {
		if (!bulletUseFlag[index]) { continue; }
		bulletPos[index].x = bulletPos[index].x + bulletSpeed * cosf(bulletRot[index]);
		bulletPos[index].y = bulletPos[index].y - bulletSpeed * sinf(bulletRot[index]);
	}

	//�e�̃����[�h�J�n
	if (PLAYER_BULLET_MAX > bulletCount) {
		if (PadInput::Push(playerIndex, XINPUT_BUTTON_X)|| bulletCount <= 0) {
			bulletReloadFlag = true;
		}
	}

	//�e�̃����[�h����
	if (bulletReloadFlag) {
		bulletReloadCount++;
		if (bulletReloadCount >= PLAYER_BULLET_RELOAD_TIME) {
			bulletReloadCount = 0;
			bulletReloadFlag = false;
			bulletCount = PLAYER_BULLET_MAX;

			//�e�����Z�b�g
			for (int index = 0; index < PLAYER_BULLET_MAX; index++) {
				bulletUseFlag[index] = false;
			}
		}
	}
}