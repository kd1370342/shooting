#include "player.h"

#include "../../Scene.h"

void Player::Update()
{
	//ˆÚ“®
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){m_pos.x -= m_move.x;}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000){m_pos.x += m_move.x;}
	if (GetAsyncKeyState(VK_UP) & 0x8000){m_pos.y += m_move.y;}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000){m_pos.y -= m_move.y;}

	//‰æ–Ê’[‚ÉŽ~‚ß‚é
	if (m_pos.x > 640.0f - 32.0f){m_pos.x = 640.0f - 32.0f;}
	if (m_pos.x < -640.0f + 32.0f){m_pos.x = -640.0f + 32.0f;}
	if (m_pos.y > 360.0f - 32.0f){m_pos.y = 360.0f - 32.0f;}
	if (m_pos.y < -360.0f + 32.0f){m_pos.y = -360.0f + 32.0f;}

	
	if (m_aliveFlg)
	{
		//“G‚Æ‚Ì“–‚½‚è”»’è
		for (int i = 0; i < m_Owner->GetEnemy().size(); i++)
		{
			Enemy* enemy = m_Owner->GetEnemy()[i];
			if (enemy != nullptr)
			{
				if (Math::Vector2::Distance(m_pos, enemy->GetPos()) < 50.0f)
				{
					m_aliveFlg = false;
					break;
				}
			}
		}

		//“G2‚Æ‚Ì“–‚½‚è”»’è
		for (int j = 0; j < m_Owner->GetEnemy2().size(); j++)
		{
			Enemy2* enemy2 = m_Owner->GetEnemy2()[j];
			if (enemy2 != nullptr)
			{
				if (Math::Vector2::Distance(m_pos, enemy2->GetPos()) < 60.0f)
				{
					m_aliveFlg = false;
					break;
				}
			}
		}

		//“G3‚Æ‚Ì“–‚½‚è”»’è
		for (int v = 0; v < m_Owner->GetEnemy3().size(); v++)
		{
			Enemy3* enemy3 = m_Owner->GetEnemy3()[v];
			if (enemy3 != nullptr)
			{
				if (Math::Vector2::Distance(m_pos, enemy3->GetPos()) < 60.0f)
				{
					m_aliveFlg = false;
					break;
				}
			}
		}
	}


	//ˆÚ“®s—ñ
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

}

void Player::Draw()
{
	//Ž©‹@•`‰æ
	if (!m_aliveFlg) return;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 80, 80), 1.0f);
}

void Player::Init()
{
	m_pos = {};
	m_move = { 15,15 };
	m_aliveFlg = true;
}

void Player::SetTex(KdTexture* p_tex)
{
	m_tex = p_tex;
}

Math::Vector2 Player::GetPlayerPos()
{
	 return m_pos; 
}


void Player::Release()
{
}
