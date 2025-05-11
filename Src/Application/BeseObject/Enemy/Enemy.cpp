#include "Enemy.h"

#include "../../Scene.h"

void Enemy::Update()
{
	//folse�Ȃ牽�����Ȃ�
	if (!m_aliveFlg) return;

	//�ړ�
		m_pos.x -= m_move.x;

	//�ړ��s��
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Enemy::Draw()
{
	//false�Ȃ牽�����Ȃ�
	if (!m_aliveFlg) return;

	//�G�`��
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&e_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void Enemy::Init()
{
	e_tex.Load("Texture/enemy.png");


	m_pos = { 640.0f + 32.0f ,static_cast<float>(rand() % 721 - 360) };//�����_����Y���W���擾
	m_move = { 2,5 };
}

void Enemy::Release()
{
	//�������
	e_tex.Release();
}
