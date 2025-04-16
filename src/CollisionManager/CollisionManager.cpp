#include "CollisionManager.h"

void CCollisionManager::PlayerToPlayer(Player* player) {

	if (CCollision::IsHitCircle(player[0].GetPos().x, player[0].GetPos().y, 16, player[1].GetPos().x,  player[1].GetPos().y,16)) {
	
			VECTOR pos1=CCollision::SpherePush(player[0].GetPos(), player[1].GetPos(), 8, 8);
			VECTOR pos2 = CCollision::SpherePush(player[1].GetPos(), player[0].GetPos(), 8, 8);
			player[0].SetPos(pos1);
			player[1].SetPos(pos2);
	}

}