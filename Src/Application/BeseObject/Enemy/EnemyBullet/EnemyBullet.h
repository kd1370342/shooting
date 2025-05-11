#pragma once

#include "../../BeseObject.h"

class Scene; //ëOï˚êÈåæ

class EnemyBullet : public BeseObject
{
public:

	EnemyBullet() {}
	~EnemyBullet() {}
	void Update() override;
	void Draw() override;
	void Init() override;


	void SetTex(KdTexture* p_tex) { m_tex = p_tex; }

	void SetOwner(Scene* Owner) { m_eOwner = Owner; }

	void Hit(int i) { m_enemybFlg[i] = false; }
	Math::Vector2 GetPos(int i) { return Math::Vector2(m_bulletX[i], m_bulletY[i]); }
	bool GetAliveFlg(int i) { return m_enemybFlg[i]; }

	int GetbNum() { return enemybNum; }

private:

	void Release() override;
	Scene* m_eOwner;
	static const int enemybNum = 100;
	float m_bulletX[enemybNum], m_bulletY[enemybNum];
	float m_moveX[enemybNum], m_moveY[enemybNum];
	bool m_enemybFlg[enemybNum];
	int m_enemybWait;

	Math::Vector2 e_pos;
	Math::Vector2 p_pos;
};