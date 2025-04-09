#pragma once
#include "DxLib.h"

//ナンバーフォントクラス
class CNumber
{
private:
	
	/*
	int NumberPosX;			//座標
	int NumberPosY;			//座標			
	VECTOR NumberPos;		//座標(VECTOR型)
	*/

public:
	CNumber();
	~CNumber();

	//初期化
	static void Init();

	//後処理
	static void Fin();

	//ナンバーフォント読み込み
	static void SetNumber(const char FontDataPath[128], int SizeX, int SizeY);

	//ナンバーフォント描画(等倍描画, 16*32のみ有効)
	static void DrawNumber_Normal(int Number, VECTOR Pos);

	//ナンバーフォント描画(2倍描画, 16*32のみ有効)
	static void DrawNumber_Double(int Number, VECTOR Pos);

};
