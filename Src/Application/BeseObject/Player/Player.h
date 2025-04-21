#pragma once

#include "../BeseObject.h"

class Player :public BeseObject
{
public:

	Player() {};
	~Player() { Release(); };

	void Update() override;
	void Draw() override;
	void Init() override;

private:

	void Release() override;

};