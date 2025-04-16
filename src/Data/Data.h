#pragma once
#include "../Map/Map.h"

class CData
{
private:
	//コンストラクタ・デストラクタ
	CData();
	~CData();

	static CData* cInstance;		//インスタンス

	MAP_TYPE ID;

public:
	static void Create();				//インスタンスの生成
	static void Destroy();				//インスタンスの削除
	static CData* GetInstance();		//インスタンスの取得

	MAP_TYPE GetMapID() { return ID; }	//選択マップ情報の取得
	void SetMapID(MAP_TYPE id) { ID = id; }
};
