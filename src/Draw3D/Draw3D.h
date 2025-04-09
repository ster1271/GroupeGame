#pragma once
#include "../Common.h"

class  CDraw3D
{
public:

	//3Dのボックス表示関数
	//第1引数：座標(中心でなくてもよい)
	//第2引数：表示したいボックスのサイズ
	//第3引数：色の指定(デフォルトは赤で設定)
	static void DrawBox3D(VECTOR Pos, VECTOR Size, unsigned int Color = GetColor(255, 0, 0));
	
};


