#pragma once
#include "../Common.h"

const VECTOR MAP_TIP_SIZE = VGet(32.0f, 32.0f, 0.0f);

//マップの種類
const enum MAP_TYPE
{
	MAP_TYPE_00,
	
	MAP_MAX_NUM,
};

const enum MAPTIP_TYPE
{
	MAPTIP_TYPE_00,
	MAPTIP_TYPE_01,

	MAPTIP_TYPE_NUM,
};

class CMap
{
private:
	FILE* fp;

	struct MapTipInfo
	{
		VECTOR cPos;
		VECTOR cRotate;
		VECTOR cSize;
		int iHndl;
	};

	vector<MapTipInfo> MapTipList;		//マップチップ情報格納リスト

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

	//マップの読み込み
	bool LoadMap(MAP_TYPE id);
};
