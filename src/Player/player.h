#pragma once
#include "../Common.h"


//プレイヤー
constexpr float PLAYER_SPEED = 3.7f;			//プレイヤー速度
constexpr float PLAYER_SLOW_SPEED = 2.8f;		//プレイヤー速度

//エイム
constexpr float AIM_SPEED = 8.0f;				//エイムカーソルの移動速度
constexpr float AIM_RADIUS = 300.0f;			//エイムとプレイヤーの距離

//プレイヤーの弾
constexpr int	 PLAYER_BULLET_MAX = 23;			//プレイヤー弾最大数
constexpr int	 PLAYER_BULLET_FIRE_TIME = 8;		//プレイヤー弾発射可能時間
constexpr int	 PLAYER_BULLET_RELOAD_TIME = 150;	//プレイヤー弾装填所要時間
constexpr float	 PLAYER_BULLET_SPEED = 10.0f;		//プレイヤー弾速度

//UI
constexpr int   PLAYER_UI_BULLET_X_1 = 100;		//1Pの弾座標X
constexpr int   PLAYER_UI_BULLET_X_2 = 740;		//2Pの弾座標X
constexpr int   PLAYER_UI_BULLET_Y = 48;		//弾座標Y
constexpr int	PLAYER_UI_DISTA = 3;			//弾UIの横倍率


//プレイヤークラス
class Player {
private:

	//プレイヤー
	int		imageHandle;			//プレイヤー画像
	int		playerIndex;			//プレイヤーのP
	int		size;					//プレイヤーサイズ
	VECTOR	pos;					//プレイヤー座標
	float	speed;					//プレイヤー速度
	float	rot;					//プレイヤー回転値
	float	radian;					//プレイヤーの移動方向
	
	//エイム関係
	int aimHandle;
	VECTOR aimPos;			//エイムの座標
	float aimRad;			//エイムの角度

	//プレイヤーの弾
	int		 bulletHandle;						//弾の画像
	int		 bulletSize;						//弾のサイズ
	int		 bulletCount;						//弾の残弾数
	int		 bulletInterval;					//弾のインターバル
	int		 bulletReloadCount;					//弾の装填時間
	VECTOR	 bulletPos[PLAYER_BULLET_MAX];		//弾の座標
	bool	 bulletReloadFlag;					//弾のリロードフラグ
	bool	 bulletUseFlag[PLAYER_BULLET_MAX];	//弾の使用フラグ
	float	 bulletRot[PLAYER_BULLET_MAX];		//弾の回転値
	float	 bulletSpeed;						//弾の速度
	

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

	//UIの描画
	void UiDraw();

	//破棄処理
	void Fin();

private:

	//プレイヤーの移動
	void PlayerMove();

	//エイム処理
	void Aim();

	//弾の処理
	void Bullet();


public:

	//プレイヤーが何Pかセット
	void SetPlayerP(int player_p) { playerIndex = player_p; }
};