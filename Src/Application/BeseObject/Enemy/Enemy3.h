#pragma once

#include "../BeseObject.h"

class Scene; //‘O•ûéŒ¾

class Enemy3 : public BeseObject
{
public:

	Enemy3() {}
	~Enemy3() {}
	void Update() override;
	void Draw() override;
	void Init() override;

	void SetOwner(Scene* Owner) { m_bOwner = Owner; }
	Math::Vector2 GetPos() { return m_pos; }
	void Hit() { m_aliveFlg = false; }
	bool Enemy3Alive() { return m_aliveFlg; }

private:

	void Release() override;
	Scene* m_bOwner;

	KdTexture e_tex;
	KdTexture k_tex;

	float k_bright = 1.0f;
	float k_brightmove = 0.09f;
	bool k_Flg;
	Math::Vector2 k_pos;
	Math::Matrix k_mat;

	int enemycount;
};
