#include "Enemy2.h"

#include "../../Scene.h"

void Enemy2::Update()
{
	//folse�Ȃ牽�����Ȃ�
	if (!m_aliveFlg) return;

	//�ړ�
	m_pos.x -= m_move.x;
	m_pos.y += m_move.y;

	if (m_pos.x < 600.0f)//600�ȉ��ɂȂ����Ƃ�
	{
		m_move.x -= 0.05f;

		if (m_move.x < 0.0f)
		{
			m_move.x = 0.0f;
			if (!justOnce)
			{
				m_move.y = std::rand() % 2 == 0 ? 3 : -3; // 2����1�̊m���ŏ㉺���]
				justOnce = true;
			}
		}
	}

	if (m_pos.y > 360.0f - 32.0f)
	{
		m_move.y *= -1;
	}
	if (m_pos.y < -360.0f + 32.0f)
	{
		m_move.y *= -1;
	}


	//�ړ��s��
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Enemy2::Draw()
{
	//false�Ȃ牽�����Ȃ�
	if (!m_aliveFlg) return;

	//�G�`��
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&e_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);

}

void Enemy2::Init()
{
	e_tex.Load("Texture/enemy.png");

	m_pos = { 640.0f + 32.0f ,static_cast<float>(rand() % 650 - 325) };//�����_����Y���W���擾
	m_move = { 4,0 };
	justOnce = false;
}

void Enemy2::Release()
{
	//�������
	e_tex.Release();
}