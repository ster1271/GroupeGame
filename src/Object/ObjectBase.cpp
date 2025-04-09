#include "ObjectBase.h"

//コンストラクタ
CObjectBase::CObjectBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&MoveVec, 0, sizeof(VECTOR));
	MoveDis = 0.0f;

	iHndl = -1;
	IsActive = false;
}


//デストラクタ
CObjectBase::~CObjectBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&MoveVec, 0, sizeof(VECTOR));
	MoveDis = 0.0f;

	iHndl = -1;
	IsActive = false;
}


//初期化
void CObjectBase::Init()
{
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;
	MoveVec = VECTOR_ZERO;
	MoveDis = 0.0f;

	iHndl = -1;
	IsActive = false;
}


//後処理
void CObjectBase::Exit()
{
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;
	MoveVec = VECTOR_ZERO;
	MoveDis = 0.0f;

	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
		IsActive = false;
	}
}


//読み込み関連
void CObjectBase::Load(int Hndl)
{
	//モデルの読み込み
	iHndl = MV1DuplicateModel(Hndl);

	Update();
}


//描画
void CObjectBase::Draw()
{
	if (iHndl != -1)
	{
		//モデルの描画
		MV1DrawModel(iHndl);
	}
}


//毎フレーム行う処理
void CObjectBase::Step() {};


//更新処理
void CObjectBase::Update()
{
	cPos = cNextPos;
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cScale);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}
