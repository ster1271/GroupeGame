#pragma once
#include "DxLib.h"


//コントローラーからの入力（Xinput）
class PadInput{
public:

	static XINPUT_STATE  input[2];

	static bool connectPad[2];

	static bool currentLStickXBuf[2];

	static bool preLStickXBuf[2];

	static bool currentLStickYBuf[2];

	static bool preLStickYBuf[2];


	//インプット初期化
	static void Init();

	//インプット通常処理
	static void Step();

	//今押された
	static bool Push(int pad_no,int button_index);

	//押されている
	static bool Keep(int pad_no, int button_index);

	//離された
	static bool Release(int pad_no, int button_index);

	//前フレームから離された
	static bool Release2(int pad_no, int button_index);

	//LスティックのX値を得る
	static int GetLX(int pad_no) {
		if(abs(input[pad_no].ThumbLX) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbLX;
	}

	//Lスティックが押された瞬間のX値を得る
	static int GetPushLX(int pad_no) {
		if (currentLStickXBuf[pad_no] == 1 && preLStickXBuf[pad_no] == 0) {
			return input[pad_no].ThumbLX;
		}
		return 0;
	}

	//LスティックのY値を得る
	static int GetLY(int pad_no) {
		if (abs(input[pad_no].ThumbLY) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbLY;
	}

	//Lスティックが押された瞬間のY値を得る
	static int GetPushLY(int pad_no) {
		if (currentLStickYBuf[pad_no] == 1 && preLStickYBuf[pad_no] == 0) {
			return input[pad_no].ThumbLY;
		}
		return 0;
	}

	//RスティックのX値を得る
	static int GetRX(int pad_no) {
		if (abs(input[pad_no].ThumbRX) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbRX;
	}

	//RスティックのY値を得る
	static int GetRY(int pad_no) {
		if (abs(input[pad_no].ThumbRY) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbRY;
	}
};