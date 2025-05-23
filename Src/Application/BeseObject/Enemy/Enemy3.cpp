#include "Enemy3.h"

#include "../../Scene.h"

void Enemy3::Update()
{
	//folseなら何もしない
	if (!m_aliveFlg) return;

	if (k_Flg)
	{
		//警告のY座標を敵のY座標に合わせる
		k_pos.y = m_pos.y;
		k_bright -= k_brightmove;//明るさを減少
		enemycount++;//カウントを増加
		if (enemycount > 60)
		{
			k_Flg = false;
			m_move.x = 100.0f;
		}
	}


	m_pos.x -= m_move.x;//敵の移動
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





	//移動行列
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	k_mat = Math::Matrix::CreateTranslation(0, k_pos.y, 0);
}

void Enemy3::Draw()
{
	//falseなら何もしない
	if (!m_aliveFlg) return;

	if (k_Flg)
	{
		//警告描画
		SHADER.m_spriteShader.SetMatrix(k_mat);
		SHADER.m_spriteShader.DrawTex(&k_tex, Math::Rectangle(0, 0, 1280, 64), k_bright);
	}

	//敵描画
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&e_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);

}

void Enemy3::Init()
{
	e_tex.Load("Texture/enemy.png");
	k_tex.Load("Texture/警告.png");

	m_pos = { 640.0f + 32.0f ,static_cast<float>(rand() % 600 - 300) };//ランダムなY座標を取得
	m_move = {0,0};
	k_pos = { 0,0 };
	enemycount = 0;
	k_Flg = true;
}

void Enemy3::Release()
{
	//解放処理
	e_tex.Release();
}
