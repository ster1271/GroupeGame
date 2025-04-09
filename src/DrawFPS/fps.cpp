#include "fps.h"

//初期化
void CFps::Init()
{
	memset(&frameRateInfo, 0, sizeof(FrameRateInfo));
}

//FPS計算
void CFps::CalcFPS()
{
	//前回のFPSを計算した時間から経過時間を求める
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//前回のFPSを計算した時間から
	//１秒以上経過していたらFPSを計算する
	if (difTime > 1000)
	{
		//フレーム回数をミリ秒に合わせる
		//小数まで出したいのでfloatにキャスト
		float frameCount = (float)(frameRateInfo.g_count * 1000.0f);

		//FPSを求める
		//理想の数値は6000/1000で60となる
		frameRateInfo.fps = frameCount / difTime;

		//フレームカウントをクリア
		frameRateInfo.g_count = 0;

		//FPSを計算した時間を更新
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS表示
void CFps::DrawFPS()
{
	unsigned int color = GetColor(255, 0, 0);
	DrawFormatString(SCREEN_SIZE_X-100, SCREEN_SIZE_Y-20, color, "FPS[%.2f]", frameRateInfo.fps);
}