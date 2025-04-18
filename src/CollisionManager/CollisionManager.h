#pragma once
#include "Collision/Collision.h"
#include "../Debug/DebugString.h"
#include "../Player/player.h"
#include "../Map/Map.h"

//コリジョンマネージャークラス
class CCollisionManager
{
private:

public:

	//プレイヤーどうしの当たり判定
	void PlayerToPlayer(Player *player);

	//プレイヤーと弾の当たり判定
	void PlayerToBullet(Player* player);

	//プレイヤーとマップの当たり安定
	void PlayerToMap(Player* player, CMap map);

	//プレイヤー弾とマップの当たり判定
	void BulletToMap(Player* player, CMap map);
};
