#pragma once

class BeseObject
{
public:
	BeseObject() {}
	~BeseObject() { Release(); }

	virtual void Draw();
	virtual void Action();
	virtual void Update();
	virtual void Init();

protected:

	virtual void Release();

	KdTexture* m_tex;
	Math::Matrix m_mat;

	Math::Vector2 m_pos = {};
	Math::Vector2 m_move = {};

	bool m_aliveFlg = true;

};