#pragma once
#include "../Common.h"

const VECTOR MAP_TIP_SIZE = VGet(32.0f, 32.0f, 0.0f);

class CMap
{
private:
	VECTOR cPos;
	VECTOR cRotate;
	VECTOR cSize;
	int iHndl;

public:
	//コンストラクタ・デストラクタ
	CMap();
	~CMap();

	//初期化
	void Init();

	//後処理
	void Exit();

	//読み込み
	void Load();

	//情報更新
	void UpData();

	//本処理
	void Step();

	//描画
	void Draw();
};
