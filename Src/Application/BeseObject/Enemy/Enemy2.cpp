#include "Enemy2.h"

#include "../../Scene.h"

void Enemy2::Update()
{
	//folseなら何もしない
	if (!m_aliveFlg) return;

	//移動
	m_pos.x -= m_move.x;
	m_pos.y += m_move.y;

	if (m_pos.x < 600.0f)//600以下になったとき
	{
		m_move.x -= 0.05f;

		if (m_move.x < 0.0f)
		{
			m_move.x = 0.0f;
			if (!justOnce)
			{
				m_move.y = std::rand() % 2 == 0 ? 3 : -3; // 2分の1の確率で上下反転
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


	//移動行列
	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void Enemy2::Draw()
{
	//falseなら何もしない
	if (!m_aliveFlg) return;

	//敵描画
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&e_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);

}

void Enemy2::Init()
{
	e_tex.Load("Texture/enemy.png");

	m_pos = { 640.0f + 32.0f ,static_cast<float>(rand() % 650 - 325) };//ランダムなY座標を取得
	m_move = { 4,0 };
	justOnce = false;
}

void Enemy2::Release()
{
	//解放処理
	e_tex.Release();
}