#include "player.h"
#include "../Input/PadInput.h"
#include "math.h"


//�v���C���[�R���X�g���N�^
Player::Player() {
	playerIndex = -1;
	imageHandle=-1;
	memset(&pos,0,sizeof(VECTOR));
	size = -1;
	rot = -1.0f;
	radian = -1.0f;
}


//�v���C���[������
void Player::Init() {
	if (playerIndex == 0) {
		PadInput::Init();
	}
}


//�v���C���[�ǂݍ���
void Player::Load() {

}


//�v���C���[�ʏ폈��
void Player::Step() {


	if (playerIndex == 0) {
		PadInput::Step();
	}

	if (PadInput::GetLX(playerIndex) != 0 && PadInput::GetLY(playerIndex) != 0) {

		//�Q�_�Ԃ̃��W�A���p�𓾂�
		radian = atan2(PadInput::GetLY(playerIndex) - 0, PadInput::GetLX(playerIndex) - 0);
	
	}


	
	
	pos.x-= PLAYER_SPEED;
	


}


//�v���C���[�`��
void Player::Draw() {

	DrawCircle(pos.x, pos.y, 16, 255);
}


//�v���C���[�j��
void Player::Fin() {

}