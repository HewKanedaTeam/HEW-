#pragma once
#include"Character.h"

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
	protected:
		int hp;
		bool isGround;

	private:
		bool isJump;
		bool isBlink;
		bool isHit;
		bool isWall;
		bool isWallJump;
		bool isDodge;

	public:
		void Move();
		void HitCheck();
		void Attack();
		void Blink();
		void Jump();
		void WallJump();
		void GetBlink();
};

