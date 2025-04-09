#pragma once
#include <DxLib.h>
#include "../Common.h"

//設定フレームレート（60FPS）
#define FRAME_RATE	(60)

//１フレームの時間（ミリ秒）
#define FRAME_TIME	(1000 / FRAME_RATE)

struct FrameRateInfo
{
	int currentTime;	//現在の時間
	int LastFrameTime;	//前回のフレーム実行時の時間
	int g_count;			//フレームカウント用
	int calcFpsTime;	//FPSを計算した時間
	float fps;			//計算したFPS(表示用)
};

class CFps
{
public:
	//フレームレート情報変数
	FrameRateInfo frameRateInfo;

public:
	//初期化
	void Init();

	//FPS計算
	void CalcFPS();

	//FPS表示(デバック用）
	void DrawFPS();
};
