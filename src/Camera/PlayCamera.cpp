#include "DxLib.h"
#include "math.h"
#include "PlayCamera.h"
#include "../MyLibrary/MyLibrary.h"
#include "../Effect/EffectManager.h"

//カメラの距離
#define CAMERA_LENGTH	(80.0f)

//視点の高さ
#define CAMERA_OFFSET_Y	(80.0f)

//注視点の高さ
#define FORCUS_OFFSET_Y	(30.0f)

//コンストラクタ
CPlayCamera::CPlayCamera()
{
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&ForcusPos, 0, sizeof(VECTOR));
	memset(&Up, 0, sizeof(VECTOR));

}

//デストラクタ
CPlayCamera::~CPlayCamera()
{
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&ForcusPos, 0, sizeof(VECTOR));
	memset(&Up, 0, sizeof(VECTOR));
}

//初期化
void CPlayCamera::Init()
{
	//念のため初期値を設定
	CameraPos = VGet(0.0f, 0.0f, 1.0f);
	ForcusPos = VGet(0.0f, 0.0f, 1.0f);
	Up = VGet(0.0f, 1.0f, 0.0f);	
}

//初期化
void CPlayCamera::Init(VECTOR vPos, VECTOR vForcusPos, VECTOR vUp)
{
	CameraPos = vPos;
	ForcusPos = vForcusPos;
	Up = vUp;
}

//毎フレーム呼ぶ処理
void CPlayCamera::Step(VECTOR vForcus, VECTOR fRot)
{
	VECTOR vDir;
	vDir.x = sinf(0.0f) * CAMERA_LENGTH;
	vDir.z = cosf(0.0f) * CAMERA_LENGTH;

	//視点の高さは固定
	vDir.y = CAMERA_OFFSET_Y;

	//注視点(プレイヤー)の位置から計算結果の距離を移動させればカメラの視点になる
	CameraPos = VAdd(vForcus, vDir);

	//注視点はターゲットの位置を利用する
	ForcusPos = vForcus;
	ForcusPos.y = FORCUS_OFFSET_Y;

	Rot = fRot;
}

//更新したデータを反映させる
void CPlayCamera::Update()
{
	SetCameraPositionAndTargetAndUpVec(CameraPos, ForcusPos, Up);
	CEffectManager::GetInstance()->UpData(CameraPos, Rot, Up);
}


//後処理
void CPlayCamera::Exit()
{
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&ForcusPos, 0, sizeof(VECTOR));
	memset(&Up, 0, sizeof(VECTOR));
}
