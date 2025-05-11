#pragma once
#include "BeseObject/Player/Player.h"
#include "BeseObject/Bullet/Bullet.h"
#include "BeseObject/Enemy/Enemy.h"
#include "BeseObject/Enemy/EnemyBullet/EnemyBullet.h"
#include "BeseObject/Enemy/Enemy2.h"
#include "BeseObject/Enemy/Enemy3.h"
#include "BeseObject/Bomb/Bomb.h"


enum SceneType
{
	Title,
	Game,
	Result,
	GameOver
};

class Scene
{
private:

	//©‹@
	Player m_player;
	KdTexture m_playerTex;

	//’e
	Bullet m_bullet;
	KdTexture m_bulletTex;

	//…•—‘D
	Bomb m_bomb;
	KdTexture m_bombTex;

	//“G
	std::vector<Enemy*> m_enemy;
	std::vector<Enemy2*> m_enemy2;
	std::vector<Enemy3*> m_enemy3;

	//“G‚Ì”
	int m_enemyNum = 5;
	int m_enemy2Num = 1;
	int m_enemy3Num = 1;

	//“G‚Ì’e
	EnemyBullet m_enemyBullet;
	KdTexture m_enemyBulletTex;

	//ƒV[ƒ“ŠÇ—
	SceneType nowScene;

public:

	// ‰Šúİ’è
	void Init();

	// ‰ğ•ú
	void Release();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	//ƒŠƒZƒbƒgŠÖ”
	void Reset();

	// GUIˆ—
	void ImGuiUpdate();

	Player* GetPlayer() { return &m_player; }

	Bullet* GetBullet() { return &m_bullet; }

	EnemyBullet* GetEnemyBullet() { return &m_enemyBullet; }

	std::vector<Enemy*> GetEnemy() { return m_enemy; }
	std::vector<Enemy2*> GetEnemy2() { return m_enemy2; }
	std::vector<Enemy3*> GetEnemy3() { return m_enemy3; }

	
private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
