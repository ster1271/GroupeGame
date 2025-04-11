#include "DxLib.h"
#include "PadInput.h"


#define BUTTON_BUF_LEN (16)

bool PadInput::connectPad[2];

bool currentButtonBuf[2][BUTTON_BUF_LEN] = { 0 };

bool preButtonBuf[2][BUTTON_BUF_LEN] = { 0 };

 bool PadInput::currentLStickXBuf[2];

 bool PadInput::preLStickXBuf[2];

 bool PadInput::currentLStickYBuf[2];

 bool PadInput::preLStickYBuf[2];

XINPUT_STATE PadInput::input[2];

//������
void PadInput::Init() {

	for (int p_index = 0; p_index < 2; p_index++) {
		for (int index = 0; index < BUTTON_BUF_LEN; index++) {
			currentButtonBuf[p_index][index] = 0;
			preButtonBuf[p_index][index] = 0;
		}
	}
	SetJoypadDeadZone(DX_INPUT_PAD1, 0.1);
	SetJoypadDeadZone(DX_INPUT_PAD2, 0.1);
}


//�O�t���ƌ��t�����L�^(�V�[���Ǘ��̑O�ɌĂԕK�v����)
void PadInput::Step() {

	for (int p_index = 0; p_index < 2; p_index++) {
		for (int index = 0; index < BUTTON_BUF_LEN; index++) {
			preButtonBuf[p_index][index] = currentButtonBuf[p_index][index];
		}
		preLStickXBuf[p_index] = currentLStickXBuf[p_index];

		preLStickYBuf[p_index] = currentLStickYBuf[p_index];
	
	}
	
	// ���͏�Ԃ��擾
	GetJoypadXInputState(DX_INPUT_PAD1, &input[0]);
	// ���͏�Ԃ��擾
	GetJoypadXInputState(DX_INPUT_PAD2, &input[1]);

	for (int p_index = 0; p_index < 2; p_index++) {
		for (int index = 0; index < BUTTON_BUF_LEN; index++) {
			if (input[p_index].Buttons[index] > 0) {
				currentButtonBuf[p_index][index] = 1;
			}
			else {
				currentButtonBuf[p_index][index] = 0;
			}
		}
	
		if (GetLX(p_index) != 0) {
			currentLStickXBuf[p_index] = 1;
		}
		else {
			currentLStickXBuf[p_index] = 0;
		}

		if (GetLY(p_index) != 0) {
			currentLStickYBuf[p_index] = 1;
		}
		else {
			currentLStickYBuf[p_index] = 0;
		}
	}


}


//�������ꂽ
bool PadInput::Push(int pad_no, int button_index) {
	if (!connectPad) { return false; }
	//�O�t���ŉ�����Ă��Ȃ����A���t���ŉ�����Ă���
	if (preButtonBuf[pad_no][button_index] == 0 && currentButtonBuf[pad_no][button_index] == 1) {
		return true;
	}
	else {
		//������Ă��Ȃ��̂� false
		return false;
	}
}


//������Ă���
bool PadInput::Keep(int pad_no, int button_index) {
	if (!connectPad) { return false; }
	//���t���ŉ�����Ă���
	if (currentButtonBuf[pad_no][button_index] == 1) {
		return true;
	}
	else {
		return false;
	}
}


//�����ꂽ
bool PadInput::Release(int pad_no, int button_index) {
	if (!connectPad) { return false; }
	//�O�t���ŉ�����Ă��邩�A���t���ŉ�����Ă��Ȃ��B
	if (preButtonBuf[pad_no][button_index] == 1 && currentButtonBuf[pad_no][button_index] == 0) {
		return true;
	}
	else {
		return false;
	}
}


bool PadInput::Release2(int pad_no, int button_index) {
	if (!connectPad) { return false; }
	//�O�t���ŉ�����Ă��Ȃ����A���t���ŉ�����Ă��Ȃ��B
	if (preButtonBuf[pad_no][button_index] == 0 && currentButtonBuf[pad_no][button_index] == 0) {
		return true;
	}
	else {
		return false;
	}
}

