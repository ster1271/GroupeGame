#include "CollisionManager.h"

void CCollisionManager::PlayerToPlayer(Player* player) {

	if (CCollision::IsHitCircle(player[0].GetPos().x, player[0].GetPos().y, 16, player[1].GetPos().x,  player[1].GetPos().y,16)) {
	
			VECTOR pos1=CCollision::SpherePush(player[0].GetPos(), player[1].GetPos(), 16, 16);
			VECTOR pos2 = CCollision::SpherePush(player[1].GetPos(), player[0].GetPos(), 16, 16);
			player[0].SetPos(pos1);
			player[1].SetPos(pos2);
	}

}

//プレイヤーと弾の当たり判定
void CCollisionManager::PlayerToBullet(Player* player) {
	
	//プレイヤー１と弾
	for (int b_index = 0; b_index < PLAYER_BULLET_MAX; b_index++) {
		if (!player[1].GetUse(b_index)) { continue; }
		if (CCollision::IsHitCircle(player[0].GetPos().x, player[0].GetPos().y, 16, player[1].GetBulletPos(b_index).x, player[1].GetBulletPos(b_index).y, 16)) {
			player[0].Damage(player[1].GetAttackPower());
			player[1].SetUse(b_index);

		}
	}

	//プレイヤー２と弾
	for (int b_index = 0; b_index < PLAYER_BULLET_MAX; b_index++) {
		if (!player[0].GetUse(b_index)) { continue; }
		if (CCollision::IsHitCircle(player[1].GetPos().x, player[1].GetPos().y, 16, player[0].GetBulletPos(b_index).x, player[0].GetBulletPos(b_index).y, 16)) {
			player[1].Damage(player[0].GetAttackPower());
			player[0].SetUse(b_index);

		}
	}
}