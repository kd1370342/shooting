#pragma once

class Scene;

class player
{
public:
	player();
	~player();

	void Init();
	void Update();
	void Draw();


private:
	KdTexture playerTex;

	Math::Vector2 pos, move;

};
