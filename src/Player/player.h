#pragma once
#include "DxLib.h"


constexpr float PLAYER_SPEED = 3.0f;		//プレイヤー速度


//プレイヤークラス
class Player {
private:

	int playerIndex;		//プレイヤーのP
	int imageHandle;		//プレイヤー画像
	VECTOR pos;				//プレイヤー座標
	int size;				//プレイヤーサイズ
	float rot;				//プレイヤー回転値
	float radian;			//プレイヤーの移動方向

public:

	Player();
	~Player(){};

	//初期化
	void Init();

	//読み込み
	void Load();

	//通常処理
	void Step();

	//描画処理
	void Draw();

	//破棄処理
	void Fin();


	//プレイヤーが何Pかセット
	void SetPlayerP(int player_p) { playerIndex = player_p; }
};