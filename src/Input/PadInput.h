#pragma once
#include "DxLib.h"


//�R���g���[���[����̓��́iXinput�j
class PadInput{
public:

	static XINPUT_STATE  input[2];

	static bool connectPad[2];

	static bool currentLStickXBuf[2];

	static bool preLStickXBuf[2];

	static bool currentLStickYBuf[2];

	static bool preLStickYBuf[2];


	//�C���v�b�g������
	static void Init();

	//�C���v�b�g�ʏ폈��
	static void Step();

	//�������ꂽ
	static bool Push(int pad_no,int button_index);

	//������Ă���
	static bool Keep(int pad_no, int button_index);

	//�����ꂽ
	static bool Release(int pad_no, int button_index);

	//�O�t���[�����痣���ꂽ
	static bool Release2(int pad_no, int button_index);

	//L�X�e�B�b�N��X�l�𓾂�
	static int GetLX(int pad_no) {
		if(abs(input[pad_no].ThumbLX) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbLX;
	}

	//L�X�e�B�b�N�������ꂽ�u�Ԃ�X�l�𓾂�
	static int GetPushLX(int pad_no) {
		if (currentLStickXBuf[pad_no] == 1 && preLStickXBuf[pad_no] == 0) {
			return input[pad_no].ThumbLX;
		}
		return 0;
	}

	//L�X�e�B�b�N��Y�l�𓾂�
	static int GetLY(int pad_no) {
		if (abs(input[pad_no].ThumbLY) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbLY;
	}

	//L�X�e�B�b�N�������ꂽ�u�Ԃ�Y�l�𓾂�
	static int GetPushLY(int pad_no) {
		if (currentLStickYBuf[pad_no] == 1 && preLStickYBuf[pad_no] == 0) {
			return input[pad_no].ThumbLY;
		}
		return 0;
	}

	//R�X�e�B�b�N��X�l�𓾂�
	static int GetRX(int pad_no) {
		if (abs(input[pad_no].ThumbRX) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbRX;
	}

	//R�X�e�B�b�N��Y�l�𓾂�
	static int GetRY(int pad_no) {
		if (abs(input[pad_no].ThumbRY) < 2000) {
			return 0;
		}
		return input[pad_no].ThumbRY;
	}
};