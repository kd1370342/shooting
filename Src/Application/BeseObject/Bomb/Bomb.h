#pragma once

#include "../BeseObject.h"

class Scene;//‘O•ûéŒ¾

class Bomb :public BeseObject
{
public:
	Bomb() {}
	~Bomb() {}
	void Update() override;
	void Draw() override;
	void Init() override;

	void SetTex(KdTexture* b_Tex) { m_tex = b_Tex; }
	void SetOwner(Scene* Owner) { m_Owner = Owner; }
	Math::Vector2 GetPos() { return m_pos; }
	void Hit() { m_aliveFlg = false; }
	bool BombAlive() { return m_aliveFlg; }

private:
	void Release() override;

	static const int bombNum = 3;
	float m_bombX[bombNum], m_bombY[bombNum];
	bool m_bombFlg[bombNum];
	bool KeyFlg;

	Math::Vector2 p_pos;

	Scene* m_Owner;
};