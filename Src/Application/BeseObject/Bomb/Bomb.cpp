#include "Bomb.h"

#include "../../Scene.h"

void Bomb::Update()
{
	Player* player = m_Owner->GetPlayer();
	
	if (GetAsyncKeyState('B') & 0x8000)
	{

		if (!KeyFlg)
		{
			if (player != nullptr) { p_pos = player->GetPlayerPos(); }

			for (int i = 0; i < bombNum; i++)
			{

				if (!m_bombFlg[i])
				{
					m_bombX[i] = p_pos.x;
					m_bombY[i] = p_pos.y;
					m_bombFlg[i] = true;

					KeyFlg = true;
					break;
				}
			}
		}
	}
	else { KeyFlg = false; }
	
}

void Bomb::Draw()
{
	//•`‰æ
	for (int i = 0; i < bombNum; i++)
	{
		if (m_bombFlg[i])
		{
			m_mat = Math::Matrix::CreateTranslation(m_bombX[i], m_bombY[i], 0);
			SHADER.m_spriteShader.SetMatrix(m_mat);
			SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 60, 60), 1.0f);
		}
	}
}

void Bomb::Init()
{
	//‰Šú‰»
	for (int i = 0; i < bombNum; i++)
	{
		m_bombFlg[i] = false;
	}
	KeyFlg = false;
}

void Bomb::Release()
{
}
