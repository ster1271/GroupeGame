#include "Map.h"

const char MAP_TIP_PATH01[128] = { "data/play/map/MapTip01.png" };
const char MAP_TIP_PATH02[128] = { "data/play/map/MapTip02.png" };

//コンストラクタ
CMap::CMap()
{
	memset(&MapTipList, -1, sizeof(vector<MapTipInfo>));
}

//デストラクタ
CMap::~CMap()
{
	Exit();
}


//初期化
void CMap::Init()
{

}

//後処理
void CMap::Exit()
{

}

//読み込み
void CMap::Load()
{
	for (int Index = 0; Index < MAPTIP_TYPE_NUM; Index++)
	{

	}
}

//情報更新
void CMap::UpData()
{

}

//本処理
void CMap::Step()
{

}

//描画
void CMap::Draw()
{

}


//マップの読み込み
bool CMap::LoadMap(MAP_TYPE id)
{

}