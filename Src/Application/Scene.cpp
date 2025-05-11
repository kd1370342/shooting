#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	switch (nowScene)
	{
	case Title:

		break;

	case Game:



		// “G3‚Ì•`‰æ
		for (int i = 0; i < m_enemy3Num; i++)
		{
			if (m_enemy3[i] != nullptr)
			{
				m_enemy3[i]->Draw();
			}
		}


		// “G‚Ì•`‰æ
		for (int i = 0; i < m_enemyNum; i++)
		{
			if (m_enemy[i] != nullptr)
			{
				m_enemy[i]->Draw();
			}
		}

		// “G2‚Ì•`‰æ
		for (int i = 0; i < m_enemy2Num; i++)
		{
			if (m_enemy2[i] != nullptr)
			{
				m_enemy2[i]->Draw();
			}
		}

		// “G‚Ì’e‚Ì•`‰æ
		m_enemyBullet.Draw();


		if (m_player.GetAliveFlg())
		{
			m_player.Draw();
			m_bullet.Draw();
		}
		m_bomb.Draw();

		break;

	case Result:

		break;

	case GameOver:

		break;
	}
}

void Scene::Update()
{
	switch (nowScene)
	{
	case Title:


		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			nowScene = Game;
		}

		break;

	case Game:


		if (m_player.GetAliveFlg())
		{
			m_player.Update();
			m_bullet.Update();
		}
		m_bomb.Update();


		for (int i = 0; i < m_enemyNum; i++)
		{
			if (m_enemy[i] != nullptr)
			{
				m_enemy[i]->Update();

				if (m_enemy[i]->EnemyAlive() == false)
				{
					delete m_enemy[i];
					m_enemy[i] = nullptr;
				}
			}
		}

		for (int i = 0; i < m_enemy2Num; i++)
		{
			if (m_enemy2[i] != nullptr)
			{
				m_enemy2[i]->Update();

				if (m_enemy2[i]->Enemy2Alive() == false)
				{
					delete m_enemy2[i];
					m_enemy2[i] = nullptr;
				}
			}
		}

		for (int i = 0; i < m_enemy3Num; i++)
		{
			if (m_enemy3[i] != nullptr)
			{
				m_enemy3[i]->Update();

				if (m_enemy3[i]->Enemy3Alive() == false)
				{
					delete m_enemy3[i];
					m_enemy3[i] = nullptr;
				}
			}
		}

		// “G‚Ì’e‚ÌXV
		m_enemyBullet.Update();


		break;

	case Result:

		break;

	case GameOver:

		break;
	}
}

void Scene::Init()
{

	// ƒV[ƒ“‚Ì‰Šú‰»
	nowScene = Title;


	// —”‚Ì‰Šú‰»iƒvƒƒOƒ‰ƒ€‚ÌÅ‰‚Å1‰ñ‚¾‚¯ŒÄ‚Ño‚·j
	static bool srandFlg = false;

	if (!srandFlg)
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		srandFlg = true;
	}

		// ©‹@
		m_playerTex.Load("Texture/…“S–C.png");
		m_player.SetTex(&m_playerTex);
		m_player.SetOwner(this);
		m_player.Init();

		//’e
		m_bulletTex.Load("Texture/…‚Ì’e.png");
		m_bullet.SetTex(&m_bulletTex);
		m_bullet.SetOwner(this);

		//…•—‘D
		m_bombTex.Load("Texture/…•—‘D.png");
		m_bomb.SetTex(&m_bombTex);
		m_bomb.SetOwner(this);
		m_bomb.Init();

	// “G
	for (int i = 0; i < m_enemyNum; i++)
	{
		Enemy* enemy = new Enemy();
		enemy->SetOwner(this);
		enemy->Init();
		m_enemy.push_back(enemy);
	}

	for (int i = 0; i < m_enemy2Num; i++)
	{
		Enemy2* enemy2 = new Enemy2();
		enemy2->SetOwner(this);
		enemy2->Init();
		m_enemy2.push_back(enemy2);
	}

	// “G3
	for (int i = 0; i < m_enemy3Num; i++)
	{
		Enemy3* enemy3 = new Enemy3();
		enemy3->SetOwner(this);
		enemy3->Init();
		m_enemy3.push_back(enemy3);
	}

	// “G‚Ì’e
	m_enemyBulletTex.Load("Texture/bullet.png");
	m_enemyBullet.SetTex(&m_enemyBulletTex);
	m_enemyBullet.SetOwner(this);
	m_enemyBullet.Init();
}

void Scene::Reset()
{

}


void Scene::Release()
{
	m_playerTex.Release();
	m_bulletTex.Release();

	for (int i = 0; i < m_enemyNum; i++)
	{
			delete m_enemy[i];
	}

	for (int i = 0; i < m_enemy2Num; i++)
	{
		delete m_enemy2[i];
	}

	for (int i = 0; i < m_enemy3Num; i++)
	{
		delete m_enemy3[i];
	}

	m_enemy.clear();

	m_enemy2.clear();

	m_enemyBulletTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// ƒfƒoƒbƒOƒEƒBƒ“ƒhƒE
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
