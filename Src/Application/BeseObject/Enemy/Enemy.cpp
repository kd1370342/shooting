#include "Enemy.h"

#include "../../Scene.h"

void Enemy::Update()
{
	//folseなら何もしない
	if (!m_aliveFlg) return;

	//移動
		m_pos.x -= m_move.x;

	//移動行列
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Enemy::Draw()
{
	//falseなら何もしない
	if (!m_aliveFlg) return;

	//敵描画
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&e_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void Enemy::Init()
{
	e_tex.Load("Texture/enemy.png");


	m_pos = { 640.0f + 32.0f ,static_cast<float>(rand() % 721 - 360) };//ランダムなY座標を取得
	m_move = { 2,5 };
}

void Enemy::Release()
{
	//解放処理
	e_tex.Release();
}
