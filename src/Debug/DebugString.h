#pragma once
#include "DxLib.h"
#include <list>
#include <string>

using namespace std;

//デバッグフラグ
constexpr bool isDebug = true;

//文字のデフォルトカラー
#define DEFAULT_COLOR	GetColor(255, 0, 0)

//リストのサイズ
constexpr int TEXTINFO_LIST_SIZE = 100;

//表示文字列のサイズ
constexpr int CHAR_SIZE = 512;

//デバック文言表示用構造体
struct TextInfo
{
	int x;					//表示座標：X
	int y;					//表示座標：Y
	string debugString;		//文言
	unsigned int color;		//文字色
	bool isUse;				//使用フラグ
};


class CDebugString
{
private:
	/*コンストラクタ・デストラクタ
	(勝手にクラスが作られないようにするためにprivateに作る)*/
	CDebugString();
	~CDebugString();

	static CDebugString* cInstance;		//インスタンス

	list<TextInfo> cTextInfoList;		//テキスト情報格納リスト

	//listにデータを追加
	void AddTextInfo(TextInfo textinfo);


public:
	static void Create();				//インスタンスの生成

	static void Destroy();				//インスタンスの削除

	static CDebugString* GetInstance();	//インスタンスの取得

	//デバック文言データを追加
	void AddString(int x, int y, string string);
	void AddFormatString(int x, int y, const char* format, ...);

	//描画
	void Draw();

	//出力ログに表示
	void DrawLogString(string string);
	void DrawLogFormatString(const char* format, ...);

};
