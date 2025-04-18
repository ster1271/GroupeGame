#include "CollisionManager.h"

void CCollisionManager::PlayerToPlayer(Player* player) {

	if (CCollision::IsHitCircle(player[0].GetPos().x, player[0].GetPos().y, 16, player[1].GetPos().x,  player[1].GetPos().y,16)) {
	
			VECTOR pos1=CCollision::SpherePush(player[0].GetPos(), player[1].GetPos(), 16, 16);
			VECTOR pos2 = CCollision::SpherePush(player[1].GetPos(), player[0].GetPos(), 16, 16);
			player[0].SetPos(pos1);
			player[1].SetPos(pos2);
	}

}

//�v���C���[�ƒe�̓����蔻��
void CCollisionManager::PlayerToBullet(Player* player) {
	
	//�v���C���[�P�ƒe
	for (int b_index = 0; b_index < PLAYER_BULLET_MAX; b_index++) {
		if (!player[1].GetUse(b_index)) { continue; }
		if (CCollision::IsHitCircle(player[0].GetPos().x, player[0].GetPos().y, 16, player[1].GetBulletPos(b_index).x, player[1].GetBulletPos(b_index).y, 16)) {
			player[0].Damage(player[1].GetAttackPower());
			player[1].SetUse(b_index);

		}
	}

	//�v���C���[�Q�ƒe
	for (int b_index = 0; b_index < PLAYER_BULLET_MAX; b_index++) {
		if (!player[0].GetUse(b_index)) { continue; }
		if (CCollision::IsHitCircle(player[1].GetPos().x, player[1].GetPos().y, 16, player[0].GetBulletPos(b_index).x, player[0].GetBulletPos(b_index).y, 16)) {
			player[1].Damage(player[0].GetAttackPower());
			player[0].SetUse(b_index);

		}
	}
}


//�v���C���[�ƃ}�b�v�̓��������
void PlayerToMap(Player* player, CMap map) {

	////�v���C���[��l��
	//for (int p_index = 0; p_index < 2; p_index++) {
	//	
	//	//�}�b�v����
	//	for (int MapIndex = 0; MapIndex != MapTipList.size(); MapIndex++)
	//		
	//		//���͔��肵�Ȃ�
	//		if (map.MapTipList[MapIndex].Type_Id == 1 || map.MapTipList[MapIndex].Type_Id == 4) {
	//			continue;
	//		}

	//	//�����̂ő��
	//	VECTOR p_p = player[p_index].GetPos2();
	//	VECTOR m_p = map.MapTipList[MapIndex].cPos;

	//	//�����蔻����Ƃ�
	//	if (CCollision::IsHitRect(p_p.x, p_p.y, 32, 32, m_p.x, m_p.y, 32, 32)) {

	//	}
	//}
}