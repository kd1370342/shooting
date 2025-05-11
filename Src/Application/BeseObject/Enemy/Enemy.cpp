#include "Enemy.h"

#include "../../Scene.h"

void Enemy::Update()
{
	//folse‚È‚ç‰½‚à‚µ‚È‚¢
	if (!m_aliveFlg) return;

	//ˆÚ“®
		m_pos.x -= m_move.x;

	//ˆÚ“®s—ñ
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Enemy::Draw()
{
	//false‚È‚ç‰½‚à‚µ‚È‚¢
	if (!m_aliveFlg) return;

	//“G•`‰æ
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&e_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void Enemy::Init()
{
	e_tex.Load("Texture/enemy.png");


	m_pos = { 640.0f + 32.0f ,static_cast<float>(rand() % 721 - 360) };//ƒ‰ƒ“ƒ_ƒ€‚ÈYÀ•W‚ğæ“¾
	m_move = { 2,5 };
}

void Enemy::Release()
{
	//‰ğ•úˆ—
	e_tex.Release();
}
