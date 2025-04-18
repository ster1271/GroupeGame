#pragma once
#include "Collision/Collision.h"
#include "../Debug/DebugString.h"
#include "../Player/player.h"
#include "../Map/Map.h"

//�R���W�����}�l�[�W���[�N���X
class CCollisionManager
{
private:

public:

	//�v���C���[�ǂ����̓����蔻��
	void PlayerToPlayer(Player *player);

	//�v���C���[�ƒe�̓����蔻��
	void PlayerToBullet(Player* player);

	//�v���C���[�ƃ}�b�v�̓��������
	void PlayerToMap(Player* player, CMap map);

	//�v���C���[�e�ƃ}�b�v�̓����蔻��
	void BulletToMap(Player* player, CMap map);
};
