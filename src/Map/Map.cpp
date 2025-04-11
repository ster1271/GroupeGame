#include "Map.h"

const char MAP_TIP_PATH01[128] = { "data/play/map/MapTip01.png" };
const char MAP_TIP_PATH02[128] = { "data/play/map/MapTip02.png" };

//コンストラクタ
CMap::CMap()
{
	memset(&cPos, -1, sizeof(VECTOR));
	memset(&cRotate, -1, sizeof(VECTOR));

	iHndl = -1;
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