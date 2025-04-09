#pragma once
#include "../Common.h"

//インプットクラス
class CMouse
{
private:

public:
	//入力制御初期化
	static void InitMouse();

	//入力制御ステップ
	//他のStepより早く呼ぶ
	static void StepMouse();

	//今押された
	static bool IsMousePush(int Mouse_code);

	//ずっと押されている
	static bool IsMouseKeep(int Mouse_code);

	//キーを離した
	static bool IsMouseRelease(int Mouse_code);

	//単純に押されているか
	static bool IsMouseDown(int Mouse_code);

	//マウス座標から角度計算
	static float MouseToRot();
};
