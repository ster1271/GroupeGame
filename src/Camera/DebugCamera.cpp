#include "DebugCamera.h"
#include "../Input/Input.h"
#include <math.h>
#include "../MyLibrary/MyLibrary.h"

//カメラの距離
#define CAMERA_LENGTH	(-30.0f)

//視点の高さ
#define CAMERA_OFFSET_Y	(400.0f)

//注視点の高さ
#define FOCUS_OFFSET_Y	(10.0f)

//カメラの移動速度
#define CAMERA_MOVE_SPEED	(1.0f)

//カメラの回転速度
#define CAMERA_ROTATE_SPEED	(0.02f)

CDebugCamera::CDebugCamera()
{
	//初期化
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&vRot, 0, sizeof(VECTOR));
}

CDebugCamera::~CDebugCamera(){}


//初期化
void CDebugCamera::Init()
{
	CameraPos = VGet(0.0f, 30.0f, 0.0f);
	vRot = VGet(DX_PI_F, 0.0f, 0.0f);

}
void CDebugCamera::Init(VECTOR vPos, float fRot)
{
	CameraPos = vPos;
	vRot = VGet(DX_PI_F / 2.0f, 0.0f, 0.0f);
}

//毎フレーム呼ぶ処理
void CDebugCamera::Step(VECTOR vPos)
{
	VECTOR vDir;
	vDir.x = sinf(vRot.y) * CAMERA_LENGTH + 20.0f;
	vDir.z = cosf(vRot.y) * CAMERA_LENGTH - 200.0f;


	//視点の高さは固定
	vDir.y = CAMERA_OFFSET_Y;


	//注視点(プレイヤー)の位置から計算結果の距離を移動させればカメラの視点になる
	CameraPos = VAdd(vPos, vDir);

	FocusPos = vPos;
}

//更新したデータを反映させる
void CDebugCamera::Update()
{
	SetCameraPositionAndTargetAndUpVec(CameraPos, FocusPos, VGet(0.0f, 1.0f, 0.0f));
}

//-----------------------
//デバックカメラ時の表示
//-----------------------
void CDebugCamera::Draw(){}

//後処理
void CDebugCamera::Exit()
{
	//初期化
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&vRot, 0, sizeof(VECTOR));
}