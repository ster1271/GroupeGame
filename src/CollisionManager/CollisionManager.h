#pragma once
#include "Collision/Collision.h"
#include "../Debug/DebugString.h"
#include "../Player/player.h"

//�R���W�����}�l�[�W���[�N���X
class CCollisionManager
{
private:

public:

	//�v���C���[�ǂ����̓����蔻��
	void PlayerToPlayer(Player *player);

	//�v���C���[�ƒe�̓����蔻��
	void PlayerToBullet(Player* player);
};
