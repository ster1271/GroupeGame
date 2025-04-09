#pragma once
#include <DxLib.h>

//アニメ再生状態
enum ANIME_STATE
{
	ANIMESTATE_NORMAL = 0,
	ANIMESTATE_LOOP,
	ANIMESTATE_END,
};


//アニメ関連のデータをまとめた構造体
struct ANIME_DATA
{
	float m_EndFrame;
	float m_Frame;
	float m_Speed;
	int m_iHndl;
	int m_AnimID;
	int m_OldAnimID;
	int m_State;
};

static ANIME_DATA AnimDataInfo;	//アニメ再生データ

class CAnim
{
private:

public:
	//初期化
	static void Init();

	//後処理
	static void Exit();

	//アニメアップデート
	static void UpdateAnim(int iHndl);

	//リクエスト
	static void Reqest(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//ループアニメリクエスト(アニメが最終フレームになったら最初に戻る)
	static void ReqestLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//エンドループアニメリクエスト(アニメが最終フレームになったら止まる)
	static void ReqestEndLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//アニメをデタッチ
	static void DetachAnim(int iHndl);
};