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

	//自機
	Player m_player;
	KdTexture m_playerTex;

	//弾
	Bullet m_bullet;
	KdTexture m_bulletTex;

	//水風船
	Bomb m_bomb;
	KdTexture m_bombTex;

	//敵
	std::vector<Enemy*> m_enemy;
	std::vector<Enemy2*> m_enemy2;
	std::vector<Enemy3*> m_enemy3;

	//敵の数
	int m_enemyNum = 5;
	int m_enemy2Num = 1;
	int m_enemy3Num = 1;

	//敵の弾
	EnemyBullet m_enemyBullet;
	KdTexture m_enemyBulletTex;

	//シーン管理
	SceneType nowScene;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	//リセット関数
	void Reset();

	// GUI処理
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
