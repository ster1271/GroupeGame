#pragma once
#include "../Map/Map.h"

class CData
{
private:
	//コンストラクタ・デストラクタ
	CData();
	~CData();

	static CData* cInstance;		//インスタンス

	MAP_TYPE ID;

	int playerType[2];				//プレイヤータイプ(2人分)
	
	bool playerWin;					//プレイヤーの勝敗フラグtrueはプレイヤー１の勝利、falseはプレイヤー２の勝利

public:
	static void Create();				//インスタンスの生成
	static void Destroy();				//インスタンスの削除
	static CData* GetInstance();		//インスタンスの取得

	MAP_TYPE GetMapID() { return ID; }	//選択マップ情報の取得
	void SetMapID(MAP_TYPE id) { ID = id; }

	//プレイヤーのタイプをセット。引数１、0～1プレイヤーの番号、引数２、選択されたプレイヤータイプ
	void SetPlayerType(int player_p, int player_type) {
		playerType[player_p] = player_type;
	}

	int GetPlayerType(int player_p) { return playerType[player_p]; }
	
	void SetPlayerWin(bool a) { playerWin = a; };

	//プレイヤーの勝利状態を取得(trueはプレイヤー１の勝利、falseはプレイヤー２の勝利)
	bool GetPlayerWin() { return playerWin; };
};
