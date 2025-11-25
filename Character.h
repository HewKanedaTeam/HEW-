#pragma once
#include "Object.h"
class Character : public Object
{
protected:
	int hp;
	bool isGround;
	bool isNotDamage;

public:
	virtual void Move()=0;
	virtual void HitCheck()=0;
	virtual void Attack()=0;
	virtual void Jump()=0;
};
