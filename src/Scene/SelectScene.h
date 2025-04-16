#pragma once
#include "../Common.h"

class CSelectScene
{
private:

	enum tagSELECT_SCENE
	{
		SELECT_SCENE_INIT,
		SELECT_SCENE_LAOD,
		SELECT_SCENE_LOOP,
		SELECT_SCENE_END,

		SELECT_SCENE_NUM
	};

	enum tagSELECT_IMAGE
	{
		SELECT_IMAGE_CURSOR1,
		SELECT_IMAGE_CURSOR2,
		SELECT_IMAGE_CHARA1,
		SELECT_IMAGE_CHARA2,
		SELECT_IMAGE_CHARA3,

		SELECT_IMAGE_NUM
	};

	struct Image
	{
		// 座標
		float PositionX;
		float PositionY;

		float Rotate;			// 角度
		float Magnification;	// 拡大率
		float Alpha;			// アルファ値
		bool BlintFrag;			// 点滅フラグ
		int Handle;				// 画像ハンドル
	};

	const Image e_Image[SELECT_IMAGE_NUM] =
	{
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0},
		{0.0f,0.0f,0,0,0,false,0}
	};

	tagSELECT_SCENE eSceneID;

	int m_startTime;	// パソコンが起動してからの時間
	int m_NowTime;		// 現在の時間
	int m_handle[SELECT_IMAGE_NUM];
	float m_alpha;
	float m_alpha2;
	bool m_BlinkFlag;

public:
	//コンストラクタ・デストラクタ
	CSelectScene();
	~CSelectScene();

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

	void ImageMove(float PositionX, float PositionY, int time, float Radius);

	// ImageChangeScale 画像を拡縮させる
	// ==========変数==========
	// Handle		= 拡縮させたい画像ハンドル
	// Scale_Rate	= 画像の大きさ
	// Scale_Speed	= 拡縮の速さ
	void ImageChangeScale(int Handle, float Scale_Rate, float Scale_Speed);
};
