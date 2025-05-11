#include "EnemyBullet.h"

#include "../../../Scene.h"

void EnemyBullet::Update()
{

	//�e�̔���
	std::vector<Enemy2*> enemy2 = m_eOwner->GetEnemy2();

	for (int j = 0; j < enemy2.size(); j++)
	{
		if (enemy2[j] != nullptr)
		{
			e_pos = enemy2[j]->GetPos();

			for (int i = 0; i < enemybNum; i++)
			{
				if (m_enemybWait == 0 && !m_enemybFlg[i])
				{
					m_enemybFlg[i] = true;
					m_bulletX[i] = e_pos.x - 32.0f;
					m_bulletY[i] = e_pos.y;
					m_enemybWait = 60;
					break;
				}
			}
		}
	}


	//�e�̈ړ�
	for (int v = 0; v < enemybNum; v++)
	{
		if (m_enemybFlg[v])
		{
			m_bulletX[v] -= m_moveX[v];
			m_bulletY[v] += m_moveY[v];

			//�o�E���h����
			if (m_bulletY[v] > 360.0f)
			{
				m_bulletY[v] = 360.0f;
				m_moveY[v] *= -1;
			}
			if (m_bulletY[v] < -360.0f)
			{
				m_bulletY[v] = -360.0f;
				m_moveY[v] *= -1;
			}

			//��ʂ���o���e������
			if(m_bulletX[v] > 640.0f + 18.5f) { m_enemybFlg[v] = false; }
			if (m_bulletX[v] < -640.0f - 18.5f) { m_enemybFlg[v] = false; }
			if (m_bulletY[v] > 360.0f + 6.5f) { m_enemybFlg[v] = false; }
			if (m_bulletY[v] < -360.0f - 6.5f) { m_enemybFlg[v] = false; }
		}
	}

	//�e�Ǝ��@�̓����蔻��
	Player* player = m_eOwner->GetPlayer();
	p_pos = player->GetPlayerPos();

	if (player->GetAliveFlg())
	{
		for (int i = 0; i < enemybNum; i++)
		{
			if (m_enemybFlg[i] == true)
			{
				if (Math::Vector2::Distance(Math::Vector2(m_bulletX[i], m_bulletY[i]), p_pos) < 32.0f)
				{
					player->Hit();
					m_enemybFlg[i] = false;
					break;
				}
			}
		}
	}


	if (m_enemybWait > 0)
	{
		m_enemybWait--;
	}

}

void EnemyBullet::Draw()
{
	//�e�̕`��
	for (int i = 0; i < enemybNum; i++)
	{
		if (m_enemybFlg[i] == true)
		{
			m_mat = Math::Matrix::CreateTranslation(m_bulletX[i], m_bulletY[i], 0);

			SHADER.m_spriteShader.SetMatrix(m_mat);
			SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 37, 13), 1.0f);
		}
	}
}

void EnemyBullet::Init()
{
	for (int i = 0; i < enemybNum; i++)
	{
		m_bulletX[i] = 0;
		m_bulletY[i] = 0;
		m_enemybFlg[i] = false;

		m_moveX[i] = 3;
		m_moveY[i] = (std::rand() % 2 == 0) ? 7 : -7; // 2����1�̊m���ŏ㉺���]
	}

	m_enemybWait = 0;
}

void EnemyBullet::Release()
{
}
