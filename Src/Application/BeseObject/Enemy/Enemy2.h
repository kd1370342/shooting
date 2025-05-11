#pragma once

#include "../BeseObject.h"

class Scene;

class Enemy2 :public BeseObject
{
public:
	Enemy2() {}
	~Enemy2() {}

	void Update() override;
	void Draw() override;
	void Init() override;


	void SetOwner(Scene* Owner) { m_bOwner = Owner; }

	Math::Vector2 GetPos() { return m_pos; }

	void Hit() { m_aliveFlg = false; }

	bool Enemy2Alive() { return m_aliveFlg; }

private:

	void Release() override;

	Scene* m_bOwner;

	KdTexture e_tex;

	bool justOnce;

};