#pragma once
#include"Object.h"
class Character
{
protected:
	int hp;
	bool isGround;
	bool isNotDamage;

public:
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void UnInit();

	virtual void Move() = 0;
	virtual void Attack() = 0;
	virtual void Jump() = 0;
};

