#pragma once
#include"Object.h"
class Character
{
protected:
	int hp;
	bool isGround;
	bool isNotDamage;

	Object* object;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void UnInit() = 0;

	virtual void Move() = 0;
	virtual void Attack() = 0;
	virtual void Jump() = 0;
};

