#pragma once

#include "../BeseObject.h"

class Scene;

class Player :public BeseObject
{
public:

	Player() {}
	~Player() {}

	void Update() override;
	void Draw() override;
	void Init() override;
	
	void SetTex(KdTexture* p_tex);

	Math::Vector2 GetPlayerPos();

	void SetOwner(Scene* Owner) { m_Owner = Owner; }

	bool GetAliveFlg() { return m_aliveFlg; }

	void Hit() { m_aliveFlg = false; }

private:

	void Release() override;

	Scene* m_Owner;


	KdTexture* p_tex;

};