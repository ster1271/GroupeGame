#pragma once
#include "../Common.h"


//プレイヤー
constexpr int	PLAYER_MAX_HP = 100;					//プレイヤー最大HP
constexpr int	PLAYER_ATTACK_POWER[3] = { 2,5,15 };	//プレイヤー攻撃力
constexpr float PLAYER_SPEED = 3.7f;					//プレイヤー速度
constexpr float PLAYER_SLOW_SPEED = 2.5f;				//プレイヤーエイム時速度

//エイム
constexpr float AIM_SPEED = 8.0f;						//エイムカーソルの移動速度
constexpr float AIM_RADIUS = 300.0f;					//エイムとプレイヤーの距離

//プレイヤーの弾
constexpr int	 PLAYER_BULLET_MAX = 23;				//プレイヤー弾最大数
constexpr int	 PLAYER_BULLET_TIME[3] = { 6,10,50 };	//プレイヤー弾発射可能時間
constexpr int	 PLAYER_BULLET_RELOAD_TIME = 150;		//プレイヤー弾装填所要時間
constexpr float	 PLAYER_BULLET_SPEED = 10.0f;			//プレイヤー弾速度

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
	int		HP;						//プレイヤー体力
	int		def;					//プレイヤー防御力
	int		size;					//プレイヤーサイズ
	int		attackPower;			//プレイヤー攻撃力
	VECTOR	pos;					//プレイヤー座標
	float	speed;					//プレイヤー速度
	float	rot;					//プレイヤー回転値
	float	radian;					//プレイヤーの移動方向
	
	//エイム関係
	int aimHandle;			//エイムの画像
	VECTOR aimPos;			//エイムの座標
	float aimRad;			//エイムの角度

	//プレイヤーの弾
	int		 bulletHandle;						//弾の画像
	int		 bulletSize;						//弾のサイズ
	int		 bulletCount;						//弾の残弾数
	int		 bulletInterval;					//弾のインターバルカウント
	int		 MaxBulletInterval;					//弾のインターバル
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

	//プレイヤー座標取得
	VECTOR GetPos() { return pos; }

	//プレイヤーボックス座標取得
	VECTOR GetPos2() {
		VECTOR p;
		p.x = pos.x-16;
		p.y = pos.y - 16;
		p.z = 0;
		return p;
	}

	//プレイヤーボックス座標セット
	void SetPos2(VECTOR p_p) { 
		VECTOR p;
		p.x = p_p.x + 16;
		p.y = p_p.y + 16;
		p.z = 0;
		SetPos(p);
	}

	//プレイヤーサイズ取得
	int GetSize() { return 32; }

	//プレイヤー座標セット
	void SetPos(VECTOR new_pos) { pos = new_pos; }

	//プレイヤーが何Pかセット
	void SetPlayerP(int player_p) { playerIndex = player_p; }

	//プレイヤー生存状態を取得
	bool GetAlive() {
		if (HP > 0) {
			return true;
		}
		return false;
	}

	//弾座標取得
	VECTOR GetBulletPos(int index) { return bulletPos[index]; }

	//弾使用フラグを得る
	bool GetUse(int index) { return bulletUseFlag[index]; }

	//弾使用フラグ折る
	void SetUse(int index) { bulletUseFlag[index] = false; }

	//プレイヤー攻撃力を得る
	int GetAttackPower() { return attackPower; }

	//ダメージを受ける
	void Damage(int attack_power) { HP -= attack_power; }
};