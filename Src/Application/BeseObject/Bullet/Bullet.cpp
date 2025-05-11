#include "Bullet.h"

#include "../../Scene.h"


void Bullet::Update()
{
	Player* player = m_Owner->GetPlayer();
	p_pos = player->GetPlayerPos();

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		for (int i = 0; i < bulletNum; i++)
		{
			if (m_bulletWait == 0)
			{
				if (m_bulletaliveFlg[i] == false)
				{
					m_bulletaliveFlg[i] = true;
					m_bulletX[i] = p_pos.x + 30.0f;
					m_bulletY[i] = p_pos.y;
					m_bulletWait = 30;

					break;
				}
			}
		}
	}

	//íeÇÃà⁄ìÆ
	for (int v = 0; v < bulletNum; v++)
	{
		if (m_bulletaliveFlg[v] == true)
		{
			m_bulletX[v] += 10.0f;
		}
	}

	//íeÇ∆ìGÇÃìñÇΩÇËîªíË
	std::vector<Enemy*> enemy = m_Owner->GetEnemy();

	for(int i = 0; i < bulletNum; i++)
	{
		if (m_bulletaliveFlg[i] == true)
		{
			for (int j = 0; j < enemy.size(); j++)
			{
				if (enemy[j] != nullptr)
				{
					e_pos = enemy[j]->GetPos();

					if (Math::Vector2::Distance(Math::Vector2(m_bulletX[i], m_bulletY[i]), e_pos) < 32.0f)
					{
						enemy[j]->Hit();
						m_bulletaliveFlg[i] = false;
						break;
					}
				}
			}
		}
	}

	//íeÇ∆ìG2ÇÃìñÇΩÇËîªíË
	std::vector<Enemy2*> enemy2 = m_Owner->GetEnemy2();

	for (int i = 0; i < bulletNum; i++)
	{
		if (m_bulletaliveFlg[i] == true)
		{
			for (int j = 0; j < enemy2.size(); j++)
			{
				if (enemy2[j] != nullptr)
				{
					e2_pos = enemy2[j]->GetPos();

					if (Math::Vector2::Distance(Math::Vector2(m_bulletX[i], m_bulletY[i]), e2_pos) < 32.0f)
					{
						enemy2[j]->Hit();
						m_bulletaliveFlg[i] = false;
						break;
					}
				}
			}
		}
	}


	//é©ã@ÇÃíeÇ∆ìGÇÃíeÇÃìñÇΩÇËîªíË
	EnemyBullet* enemyBullet = m_Owner->GetEnemyBullet();

	for (int i = 0; i < bulletNum; i++)
	{
		if (m_bulletaliveFlg[i] == true)
		{
			for (int j = 0; j < enemyBullet->GetbNum(); j++)
			{
				if (enemyBullet->GetAliveFlg(j))
				{
					if (Math::Vector2::Distance(Math::Vector2(m_bulletX[i], m_bulletY[i]), Math::Vector2(enemyBullet->GetPos(j).x, enemyBullet->GetPos(j).y)) < 30.0f)
					{
						m_bulletaliveFlg[i] = false;
						enemyBullet->Hit(j);
						break;
					}
				}
			}
		}
	}


	//âÊñ äOÇ…èoÇΩíeÇè¡Ç∑
	for (int i = 0; i < bulletNum; i++)
	{
		if (m_bulletX[i] > 640.0f + 18.5f)
		{
			m_bulletaliveFlg[i] = false;
		}
		if (m_bulletX[i] < -640.0f - 18.5f)
		{
			m_bulletaliveFlg[i] = false;
		}
		if (m_bulletY[i] > 360.0f + 6.5f)
		{
			m_bulletaliveFlg[i] = false;
		}
		if (m_bulletY[i] < -360.0f - 6.5f)
		{
			m_bulletaliveFlg[i] = false;
		}
	}

	//bulletWaitÇÃÉJÉEÉìÉg
	m_bulletWait--;
	if (m_bulletWait < 0)
	{
		m_bulletWait = 0;
	}


}

void Bullet::Draw()
{
	for (int i = 0; i < bulletNum; i++)
	{
		if (m_bulletaliveFlg[i] == true)
		{
			m_mat = Math::Matrix::CreateTranslation(m_bulletX[i], m_bulletY[i], 0);

			SHADER.m_spriteShader.SetMatrix(m_mat);
			SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 20, 20), 1.0f);
		}
	}
	
}

void Bullet::Init()
{

	for (int i = 0; i < bulletNum; i++)
	{
		m_bulletaliveFlg[i] = false;
	}
}


void Bullet::Release()
{
}
