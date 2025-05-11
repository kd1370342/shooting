#pragma once

#include"../BeseObject.h"

class Scene;

class Enemy :public BeseObject
{
public:
	Enemy() {}
	~Enemy() {}

	void Update() override;
	void Draw() override;
	void Init() override;


	void SetOwner(Scene* Owner) { m_bOwner = Owner; }

	Math::Vector2 GetPos() { return m_pos; }

	void Hit() { m_aliveFlg = false; }

	bool EnemyAlive() { return m_aliveFlg; }

private:

	void Release() override;


	Scene* m_bOwner;

	KdTexture e_tex;

};