#include "Mouse.h"

const int MOUSE_BUF = 4;

int MouseX;		//マウスX座標
int MouseY;		//マウスY座標

char currentMouseBuf[MOUSE_BUF] = { 0 };	//現在フレームのマウス情報格納
char preMouseBuf[MOUSE_BUF] = { 0 };		//過去フレームのマウス情報格納

//入力制御初期化
void CMouse::InitMouse()
{
	MouseX = MouseY = 0;

	for (int MouseIndex = 0; MouseIndex < MOUSE_BUF; MouseIndex++)
	{
		currentMouseBuf[MouseIndex] = '\0';
		preMouseBuf[MouseIndex] = '\0';
	}
}

//入力制御ステップ
//他のStepより早く呼ぶ
void CMouse::StepMouse()
{
	//マウスポインタ座標更新
	GetMousePoint(&MouseX, &MouseY);

	for (int MouseIndex = 0; MouseIndex < MOUSE_BUF; MouseIndex++)
	{
		//過去フレームに情報を渡す
		preMouseBuf[MouseIndex] = currentMouseBuf[MouseIndex];
		//現在フレームを初期化しておく
		currentMouseBuf[MouseIndex] = '\0';
	}

	//左ボタン
	if (GetMouseInput() && MOUSE_INPUT_LEFT != 0)
	{
		currentMouseBuf[0] = 1;
	}
	//右ボタン
	if (GetMouseInput() && MOUSE_INPUT_RIGHT != 0)
	{
		currentMouseBuf[1] = 1;
	}
	//中央ボタン
	if (GetMouseInput() && MOUSE_INPUT_MIDDLE != 0)
	{
		currentMouseBuf[3] = 1;
	}
	
}

//今押された
bool CMouse::IsMousePush(int Mouse_code)
{
	//前フレで押されていない かつ 現フレで押されている
	if (preMouseBuf[Mouse_code] == 0 && currentMouseBuf[Mouse_code] == 1)
		return true;

	//押されていないので false
	return false;
}

//ずっと押されている
bool CMouse::IsMouseKeep(int Mouse_code)
{
	//前フレで押されている かつ 現フレで押されている
	if (preMouseBuf[Mouse_code] == 1 && currentMouseBuf[Mouse_code] == 1)
		return true;

	//押されていないので false
	return false;
}

//キーを離した
bool CMouse::IsMouseRelease(int Mouse_code)
{
	//前フレで押されている かつ 現フレで押されていない
	if (preMouseBuf[Mouse_code] == 1 && currentMouseBuf[Mouse_code] == 0)
		return true;

	//押されていないので false
	return false;
}

//単純に押されているか
bool CMouse::IsMouseDown(int Mouse_code)
{
	//現フレで押されている（前フレの状態は関係なし）
	if (currentMouseBuf[Mouse_code] == 1)
		return true;

	//押されていないので false
	return false;
}

//マウス座標から角度計算
float CMouse::MouseToRot()
{
	int X = MouseX - (SCREEN_SIZE_X / 2);
	int Y = MouseY - (SCREEN_SIZE_Y / 2);

	return (float)atan2((int)X, (int)Y * -1);
}
