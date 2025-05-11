#pragma once

#include "../BeseObject.h"

//ëOï˚êÈåæ
class Scene;

class Bullet : public BeseObject
{
public:

	Bullet() {}
	~Bullet() {}

	void Update() override;
	void Draw() override;
	void Init() override;


	void SetTex(KdTexture* b_Tex) { m_tex = b_Tex; }

	void SetOwner(Scene* Owner) { m_Owner = Owner; }


private:

	void Release() override;


	Scene* m_Owner;
	static const int bulletNum = 1000;
	float m_bulletX[bulletNum], m_bulletY[bulletNum];
	bool m_bulletaliveFlg[bulletNum];
	int m_bulletWait;
	int bullet = 0;

	Math::Vector2 p_pos;
	Math::Vector2 e_pos;
	Math::Vector2 e2_pos;

};