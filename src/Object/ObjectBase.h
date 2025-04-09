#pragma once
#include "../Common.h"

enum OBJECT_DIR
{
	OBJECT_DIR_UP,		//上
	OBJECT_DIR_DOWN,	//下
	OBJECT_DIR_LEFT,	//左
	OBJECT_DIR_RIGHT,	//右

	OBJECT_DIR_NUM,		//総番号
};

//オブジェクトクラス
class CObjectBase
{
protected:
	VECTOR cPos;		//座標
	VECTOR cNextPos;	//1フレーム後の座標
	VECTOR cRotate;		//回転値
	VECTOR cSize;		//サイズ(縦幅、横幅、奥行)
	VECTOR cScale;		//拡大倍率
	VECTOR MoveVec;		//移動ベクトル
	float MoveDis;		//移動量
	
	int iHndl;			//ハンドル

	bool IsActive;		//フラグ 

public:
	//コンストラクタ・デストラクタ
	CObjectBase();
	~CObjectBase();

	const VECTOR GetPos() { return cPos; }
	const VECTOR GetNextPos() { return cNextPos; }
	const VECTOR GetSize() { return cSize; }
	const VECTOR GetRotate() { return cRotate; }
	const VECTOR GetMoveVec() { return MoveVec; }

	void SetPos(VECTOR NewPos) { cPos = NewPos; }
	void SetRotate(VECTOR NewRotate) { cRotate = NewRotate; }


	//初期化
	void Init();

	//後処理
	void Exit();

	//読み込み関連
	void Load(int Hndl);

	//描画
	void Draw();

	//本体処理
	virtual void Step();

	//更新処理
	void Update();



};
