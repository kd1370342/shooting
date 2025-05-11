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

	//���@
	Player m_player;
	KdTexture m_playerTex;

	//�e
	Bullet m_bullet;
	KdTexture m_bulletTex;

	//�����D
	Bomb m_bomb;
	KdTexture m_bombTex;

	//�G
	std::vector<Enemy*> m_enemy;
	std::vector<Enemy2*> m_enemy2;
	std::vector<Enemy3*> m_enemy3;

	//�G�̐�
	int m_enemyNum = 5;
	int m_enemy2Num = 1;
	int m_enemy3Num = 1;

	//�G�̒e
	EnemyBullet m_enemyBullet;
	KdTexture m_enemyBulletTex;

	//�V�[���Ǘ�
	SceneType nowScene;

public:

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw2D();

	//���Z�b�g�֐�
	void Reset();

	// GUI����
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
