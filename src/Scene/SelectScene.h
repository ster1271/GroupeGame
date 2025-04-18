#pragma once
#include "../Common.h"
#include "../Data/Data.h"
#include "../Input/Input.h"
#include "../Input/PadInput.h"

const int PLAYER_NUM = 2;

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

	enum tagSELECT_UI_IMAGE
	{
		SELECT_UI_IMAGE_CURSOR1,
		SELECT_UI_IMAGE_CURSOR2,
		SELECT_UI_IMAGE_CURSOR3,
		SELECT_UI_IMAGE_CURSOR4,
		SELECT_UI_IMAGE_TEXT1,
		SELECT_UI_IMAGE_TEXT2,
		SELECT_UI_IMAGE_TEXT3,
		SELECT_UI_IMAGE_TEXT4,
		SELECT_UI_IMAGE_TEXT5,

		SELECT_UI_IMAGE_NUM
	};

	enum tagSELECT_CHARA_IMAGE
	{
		SELECT_CHARA_IMAGE_1,
		SELECT_CHARA_IMAGE_2,
		SELECT_CHARA_IMAGE_3,

		SELECT_CHARA_IMAGE_NUM
	};

	enum tagSELECT_STAGE_IMAGE
	{
		SELECT_STAGE_IMAGE_1,
		SELECT_STAGE_IMAGE_2,
		SELECT_STAGE_IMAGE_3,

		SELECT_STAGE_IMAGE_NUM
	};

	enum tagSCREEN
	{
		SCREEN_CHARA,
		SCREEN_STAGE,

		SCREEN_NUM
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

	tagSELECT_SCENE eSceneID;

	int m_startTime;	// パソコンが起動してからの時間
	int m_NowTime;		// 現在の時間
	int m_UI_handle[SELECT_UI_IMAGE_NUM];

	int m_1PChara_handle[SELECT_CHARA_IMAGE_NUM];	//1Pキャラクター画像
	int m_1PChara_index;		//1Pキャラクター画像の添え字
	bool m_Is1PCharaSelected;	//1Pキャラクター決定判断用

	int m_2PChara_handle[SELECT_CHARA_IMAGE_NUM];	//2Pキャラクター画像
	int m_2PChara_index;		//2Pキャラクター画像の添え字
	bool m_Is2PCharaSelected;	//2Pキャラクター決定判断用

	int m_Stage_handle[SELECT_STAGE_IMAGE_NUM];
	int m_Stage_index;
	bool m_IsStageSelected;

	int m_Scene_index;
	float m_alpha;
	float m_alpha2;
	bool m_BlinkFlag;
	bool m_ExpantionFlag;	//拡大フラグ

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

	//キャラクター選択
	void ChangeCharaImage();
	//キャラクター決定
	void SelectChara();
	//キャラクターキャンセル
	void CancelChara();

	//ステージ選択
	void ChangeStageImage();
	//ステージ決定
	void SelectStage();
	//ステージキャンセル
	void CancelStage();

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
};
