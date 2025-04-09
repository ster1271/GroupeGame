#include "Animation.h"

//初期化
void CAnim::Init()
{
	memset(&AnimDataInfo, -1, sizeof(AnimDataInfo));
}

//後処理
void CAnim::Exit()
{
	memset(&AnimDataInfo, -1, sizeof(AnimDataInfo));
}

//リクエスト
void CAnim::Reqest(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	//前のアニメーションとo同じだったら処理しない
	if (AnimDataInfo.m_OldAnimID == iAnimID)
		return;

	//アニメ消失
	DetachAnim(iHndl);

	//アニメ再生&各種データをセット
	AnimDataInfo.m_iHndl = MV1AttachAnim(iHndl, iAnimID, iAnimHndl, NameCheck);
	AnimDataInfo.m_AnimID = iAnimID;
	AnimDataInfo.m_OldAnimID = AnimDataInfo.m_AnimID;
	AnimDataInfo.m_EndFrame = MV1GetAnimTotalTime(iHndl, iAnimID);
	AnimDataInfo.m_Frame = 0.0f;
	AnimDataInfo.m_Speed = iAnimSpd;
	AnimDataInfo.m_State = ANIMESTATE_NORMAL;

}

//ループアニメリクエスト(アニメが最終フレームになったら最初に戻る)
void CAnim::ReqestLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{

	Reqest(iHndl, iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//アニメ再生状態をループに変える
	AnimDataInfo.m_State = ANIMESTATE_LOOP;
}

//エンドループアニメリクエスト(アニメが最終フレームになったら止まる)
void CAnim::ReqestEndLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	Reqest(iHndl, iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//アニメ再生状態をエンドループに変える
	AnimDataInfo.m_State = ANIMESTATE_END;
}

//アニメをデタッチ
void CAnim::DetachAnim(int iHndl)
{
	if (AnimDataInfo.m_iHndl != -1)
	{
		MV1DetachAnim(iHndl, AnimDataInfo.m_iHndl);
		AnimDataInfo.m_iHndl = -1;
	}
}

//アニメアップデート
void CAnim::UpdateAnim(int iHndl)
{
	if (AnimDataInfo.m_iHndl == -1)return;	//アニメーションが再生されていない

	//アニメーション速度更新
	AnimDataInfo.m_Frame += AnimDataInfo.m_Speed;

	if (AnimDataInfo.m_Frame >= AnimDataInfo.m_EndFrame)
	{
		//最終フレームになったら、状態にあわせて動作を変える
		switch (AnimDataInfo.m_State)
		{
		case ANIMESTATE_NORMAL:	//通常終了
			DetachAnim(iHndl);
			AnimDataInfo.m_EndFrame = 0.0f;
			AnimDataInfo.m_Frame = 0.0f;
			AnimDataInfo.m_Speed = 0.0f;
			return;

		case ANIMESTATE_LOOP:	//ループを最初に戻す
			AnimDataInfo.m_Frame = 0.0f;
			break;

		case ANIMESTATE_END:
			AnimDataInfo.m_State = AnimDataInfo.m_EndFrame;
			break;

		default:
			break;
		}
	}

	//再生時間設定
	MV1SetAttachAnimTime(iHndl, AnimDataInfo.m_iHndl, AnimDataInfo.m_Frame);
}