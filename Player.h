#pragma once
#include"Character.h"
#include"Input.h"

enum PlayerState
{
	STY,
	BRINK,
	JUMP,
	NODAMAGE,
	STAN,WALL_GRAB,
	ATTACK,
	RIGHT,
	LIGHT,

};

class Player : public Character
{
private:
	int hp;
	bool isGround;
	bool isJump;
	bool isBlink;
	bool isHit;
	bool isWall;
	bool isWallJump;
	bool isDodge;

	Input input;
	Object player;

public:

	void Init()override;
	void Update()override;
	void Draw()override;
	void UnInit()override;

	void Move()override;
	void Jump()override;
	void Attack()override;

	void WallJump();
	void Blink();
	void GetBlink();
};
