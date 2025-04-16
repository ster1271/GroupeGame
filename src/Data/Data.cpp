#include "Data.h"

//インスタンスの初期化
CData* CData::cInstance = nullptr;

//コンストラクタ・デストラクタ
CData::CData() {};
CData::~CData() {};

//インスタンスの生成
void CData::Create()
{
	//インスタンスにが生成されていなかったら
	if (cInstance == nullptr)
	{
		//新しくnewする
		cInstance = new CData();
	}
}


//インスタンスの削除
void CData::Destroy()
{
	//インスタンスが生成されていたら
	if (cInstance != nullptr)
	{
		//deleteしてnullptrを入れる
		delete cInstance;
		cInstance = nullptr;
	}
}


//インスタンスの取得
CData* CData::GetInstance()
{
	if (cInstance == nullptr)
	{
		//インスタンスが生成されていなかったら生成する
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
}
