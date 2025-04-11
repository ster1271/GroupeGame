#include "player.h"
#include "../Input/PadInput.h"
#include "math.h"


//プレイヤーコンストラクタ
Player::Player() {
	playerIndex = -1;
	imageHandle=-1;
	memset(&pos,0,sizeof(VECTOR));
	size = -1;
	rot = -1.0f;
	radian = -1.0f;
}


//プレイヤー初期化
void Player::Init() {
	if (playerIndex == 0) {
		PadInput::Init();
	}
}


//プレイヤー読み込み
void Player::Load() {

}


//プレイヤー通常処理
void Player::Step() {


	if (playerIndex == 0) {
		PadInput::Step();
	}

	if (PadInput::GetLX(playerIndex) != 0 && PadInput::GetLY(playerIndex) != 0) {

		//２点間のラジアン角を得る
		radian = atan2(PadInput::GetLY(playerIndex) - 0, PadInput::GetLX(playerIndex) - 0);
	
	}


	
	
	pos.x-= PLAYER_SPEED;
	


}


//プレイヤー描画
void Player::Draw() {

	DrawCircle(pos.x, pos.y, 16, 255);
}


//プレイヤー破棄
void Player::Fin() {

}