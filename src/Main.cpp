#include "Common.h"
#include "Scene/SceneManager.h"
#include "SoundManager/SoundManager.h"
#include "DrawFont/DrawFont.h"
#include "DrawFPS/fps.h"
#include "Mouse/Mouse.h"
#include "Input/PadInput.h"


// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	// Zソート判定
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetTransColor(255, 0, 255);	// 透過色指定

	//ライト設定
	SetUseLighting(TRUE);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く

	//シーンマネージャー
	SceneManager cSceneManager;

	//FPS初期化
	CFps cFps;
	cFps.Init();

	//キーボード初期化
	CInput::InitInput();
	//ゲームパッド初期化	
	CGamePad::InitGamePad();
	PadInput::Init();
	//マウス初期化
	CMouse::InitMouse();
	//フォントデータ初期化
	CDrawFont::Init();
	//フォントデータ読み込み
	CDrawFont::LoadAllFontData();
	//サウンド初期化
	CSoundManager::Init();
	CSoundManager::LoadAllData();

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//システム処理を返す

		//現在の時間を取得
		cFps.frameRateInfo.currentTime = GetNowCount();

		//最初のループなら
		//現在の時間を、FPSの計算をした時間に設定
		if (cFps.frameRateInfo.calcFpsTime == 0.0f)
		{
			cFps.frameRateInfo.calcFpsTime = cFps.frameRateInfo.currentTime;
			cFps.frameRateInfo.fps = (float)FRAME_RATE;
		}

		//現在の時間が、前回のフレーム時より
		//1000/60ミリ秒（1/60）以上経過したいたら処理を実行する
		if (cFps.frameRateInfo.currentTime - cFps.frameRateInfo.LastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			cFps.frameRateInfo.LastFrameTime = cFps.frameRateInfo.currentTime;

			//フレーム数をカウント
			cFps.frameRateInfo.g_count++;


			//キーボード情報更新
			CInput::StepInput();
			//ゲームパッド情報更新
			CGamePad::StepGamePad();
			PadInput::Step();
			//マウス情報更新
			CMouse::StepMouse();
			
			//エスケープキーまたはスタートボタンが押されたら終了
			if (CInput::IsKeyPush(KEY_INPUT_ESCAPE) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_BACK))
				break;

			//画面に表示されたものを初期化
			ClearDrawScreen();

			//-----------------------------------------
			//ここからゲームの本体を書くことになる
			//-----------------------------------------

			//計算処理
			cSceneManager.Loop();

			//描画処理
			cSceneManager.Draw();
			

			//FPS計算
			cFps.CalcFPS();

			//FPS表示
			cFps.DrawFPS();

			//-----------------------------------------
			//ループの終わりに
			//フリップ関数
			ScreenFlip();

		}
	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く
	CDrawFont::Exit();
	CSoundManager::Exit();

	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

