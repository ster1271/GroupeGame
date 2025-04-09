#include "DrawFont.h"

//コンストラクタ
CDrawFont::CDrawFont(){}

//デストラクタ
CDrawFont::~CDrawFont(){}

//初期化
void CDrawFont::Init()
{
	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		FontHndl[FontIndex] = -1;
	}
}

//終了処理
void CDrawFont::Exit()
{
	//ロードしたフォントを解放する
	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		RemoveFontResourceEx(FontFilePath[FontIndex], FR_PRIVATE, NULL);
		FontHndl[FontIndex] = -1;
	}
}

//データの読み込み
bool CDrawFont::LoadAllFontData()
{
	bool IsLoadFont = true;
	int Index = 0;

	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		//新しくフォントデータを読み込む
		int a = AddFontResourceEx(FontFilePath[FontIndex], FR_PRIVATE, NULL);
		if (a == 0)
		{
			return false;
		}

		//読み込んだフォントデータをハンドルに保存
		//引数1：読み込むフォントデータパス
		//引数2：フォントのサイズ
		//引数2：フォントの縁の太さ(0なら縁なし)
		for (int SizeIndex = 1; SizeIndex < 5; SizeIndex++)
		{
			FontHndl[Index] = CreateFontToHandle(FontName[FontIndex], 10 * SizeIndex, 1, DX_FONTTYPE_NORMAL);

			//1つでもロード失敗があればフラグをオフに
			if (FontHndl[Index] == -1)
			{
				IsLoadFont = false;
			}

			Index++;
		}
	}
	return IsLoadFont;
}

//描画
void CDrawFont::Draw(int PosX, int PosY, FontSizeID Id,
	const TCHAR* String, unsigned int Color)
{
	DrawFormatStringToHandle(PosX, PosY, Color, FontHndl[Id], String);
}