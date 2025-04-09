#include "DebugString.h"
#include <cstdarg>	//可変引数の処理に必要
#include <cstdio>	//vsnprintの使用に必要
#include <Windows.h>

//インスタンスの初期化
CDebugString* CDebugString::cInstance = nullptr;

//コンストラクタ
CDebugString::CDebugString()
{
	//リストの初期化
	cTextInfoList.resize(TEXTINFO_LIST_SIZE);
	for (TextInfo& value : cTextInfoList)
	{
		value.isUse = false;
	}
}

//デストラクタ
CDebugString::~CDebugString()
{
}


//インスタンスの生成
void CDebugString::Create()
{
	//インスタンスにが生成されていなかったら
	if (cInstance == nullptr)
	{
		//新しくnewする
		cInstance = new CDebugString();
	}
}


//インスタンスの削除
void CDebugString::Destroy()
{
	//インスタンスが生成されていたら
	if (cInstance != nullptr)
	{
		//deleteしてnullptrを入れる
		delete cInstance;
		cInstance = nullptr;
	}
}


//インスタンスの取得
CDebugString* CDebugString::GetInstance()
{
	if (cInstance == nullptr)
	{
		//インスタンスが生成されていなかったら生成する
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
}


//デバック文言データを追加
void CDebugString::AddString(int x, int y, string string)
{
	TextInfo tmp = { x, y, string, DEFAULT_COLOR, true };
	AddTextInfo(tmp);
}

void CDebugString::AddFormatString(int x, int y, const char* format, ...)
{
	//フォーマット済みの文字列を格納するバッファ
	char buffer[CHAR_SIZE];

	//可変引数を処理
	va_list args;
	va_start(args, format);
	//フォーマット済みの文字列を生成
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	TextInfo tmp = { x, y, buffer, DEFAULT_COLOR, format };
	AddTextInfo(tmp);
}

//listにデータを追加
void CDebugString::AddTextInfo(TextInfo textInfo)
{
	for (TextInfo& value : cTextInfoList)
	{
		if (!value.isUse)
		{
			value = textInfo;
			return;
		}
	}
}


//描画
void CDebugString::Draw()
{
	if (!isDebug)
		return;

	for (TextInfo& value : cTextInfoList)
	{
		if (value.isUse)
		{
			DrawString(value.x, value.y, value.debugString.c_str(), value.color);
			//表示したら未使用にする
			value.isUse = false;
		}
	}
}

//出力ログに表示
void CDebugString::DrawLogString(string string)
{
	string += "\n";
	OutputDebugString(string.c_str());
}

//出力ログに表示
void CDebugString::DrawLogFormatString(const char* format, ...)
{
	if (!isDebug)
		return;

	//フォーマット済みの文字列を格納するバッファ
	char buffer[CHAR_SIZE];

	//可変引数を処理
	va_list args;
	va_start(args, format);
	//フォーマット済みの文字列を生成
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	DrawLogString(buffer);
}

