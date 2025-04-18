#pragma once
#include "../Common.h"
#include "../Input/PadInput.h"

class CTitleScene
{
private:

	enum tagTITLE_SCENE
	{
		TITLE_SCENE_INIT,
		TITLE_SCENE_LAOD,
		TITLE_SCENE_LOOP,
		TITLE_SCENE_END,

		TITLE_SCENE_NUM
	};

	//struct Image
	//{
	//	// 座標
	//	float PositionX;
	//	float PositionY;

	//	float Rotate;			// 角度
	//	float Magnification;	// 拡大率
	//	float Alpha;			// アルファ値
	//	bool BlintFrag;			// 点滅フラグ
	//	int Handle;				// 画像ハンドル

	//};

	/*const Image e_Image[4] =
	{
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0}
	};*/

	tagTITLE_SCENE eSceneID;

	int m_startTime;	// パソコンが起動してからの時間
	int m_NowTime;		// 現在の時間
	int m_handle;
	int m_SelectPointer;
	int m_ArrivalTime;	// 画像の到達時間
	int m_PlayerIndex[2];
	float m_alpha;
	
	bool m_BlinkFlag;

	// デバック用の変数
	float m_PosX;
	float m_PosY;
	float m_StartPosX;
	float m_StartPosY;
	float m_alpha2;
	float m_TwoPointDistance;	// 二点間の距離
	float m_TwoPointRadius;		// 二点間の角度
	int m_HoiigaHandle;
	float Angle;

public:
	//コンストラクタ・デストラクタ
	CTitleScene();
	~CTitleScene();

	//ループ処理
	int Loop();

	//初期化
	void Init();

	//終了処理
	void Exit();

	//データ読み込み
	void Load();

	//描画
	void Draw();

	//本体処理
	void Step();

	//情報更新
	void UpData();

private:

	// 描画関数

	// ImageBlink 画像を点滅させる
	// ==========変数==========
	// Handle		= 点滅させたい画像ハンドル
	// p_Alpha		= その画像のアルファ値を入れる(&をつける)
	// BlinkSpeed	= 点滅速度を入れる
	// p_BlinkFlag	= 点滅のフラグ(Falseで透明になっていく)
	// AddPace		= 値に多いほど不透明になるのが早くなる
	// SubPace		= 値が多いほど透明になるのが早くなる
	void ImageBlink(int Handle, float* p_Alpha, float BlinkSpeed, bool* p_BlinkFlag, float AddPace, float SubPace);

	void ImageMove(float StartPositionX, float StartPositionY, float EndPositionX, float EndPositionY,
					float MoveSpeed,int time, float* p_MovePositionX, float* p_MovePositionY);

};
