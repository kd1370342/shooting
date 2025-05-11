#include "Enemy3.h"

#include "../../Scene.h"

void Enemy3::Update()
{
	//folse‚È‚ç‰½‚à‚µ‚È‚¢
	if (!m_aliveFlg) return;

	if (k_Flg)
	{
		//Œx‚ÌYÀ•W‚ğ“G‚ÌYÀ•W‚É‡‚í‚¹‚é
		k_pos.y = m_pos.y;
		k_bright -= k_brightmove;//–¾‚é‚³‚ğŒ¸­
		enemycount++;//ƒJƒEƒ“ƒg‚ğ‘‰Á
		if (enemycount > 60)
		{
			k_Flg = false;
			m_move.x = 100.0f;
		}
	}


	m_pos.x -= m_move.x;//“G‚ÌˆÚ“®
	if (k_bright < 0.0f)
	{
		k_bright = 0.0f;
		k_brightmove *= -1.0f;
	}
	else if (k_bright > 1.0f)
	{
		k_bright = 1.0f;
		k_brightmove *= -1.0f;
	}





	//ˆÚ“®s—ñ
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	k_mat = Math::Matrix::CreateTranslation(0, k_pos.y, 0);
}

void Enemy3::Draw()
{
	//false‚È‚ç‰½‚à‚µ‚È‚¢
	if (!m_aliveFlg) return;

	if (k_Flg)
	{
		//Œx•`‰æ
		SHADER.m_spriteShader.SetMatrix(k_mat);
		SHADER.m_spriteShader.DrawTex(&k_tex, Math::Rectangle(0, 0, 1280, 64), k_bright);
	}

	//“G•`‰æ
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&e_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);

}

void Enemy3::Init()
{
	e_tex.Load("Texture/enemy.png");
	k_tex.Load("Texture/Œx.png");

	m_pos = { 640.0f + 32.0f ,static_cast<float>(rand() % 600 - 300) };//ƒ‰ƒ“ƒ_ƒ€‚ÈYÀ•W‚ğæ“¾
	m_move = {0,0};
	k_pos = { 0,0 };
	enemycount = 0;
	k_Flg = true;
}

void Enemy3::Release()
{
	//‰ğ•úˆ—
	e_tex.Release();
}
