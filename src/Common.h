#pragma once
#include <DxLib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <list>
#include "MyLibrary/MyLibrary.h"
#include "Input/Input.h"
#include "GamePad/GamePad.h"
#include "Draw3D/Draw3D.h"
#include "Debug/DebugString.h"

const int SCREEN_SIZE_X = 1280;	//画面サイズ 横
const int SCREEN_SIZE_Y = 720;	//画面サイズ 縦

const unsigned int COLOR = GetColor(255, 0, 0);		//デフォルトの色(赤)

const VECTOR VECTOR_ZERO = VGet(0.0f, 0.0f, 0.0f);	//VECTORの初期化に使う

const bool IS_DEBUG = true;							//デバックフラグ

using namespace std;
