#pragma once
#include "Character.h"

enum EnemyState
{
	STY,//通常
	JUMP,//ジャンプ中
	STAN,//スタン中
	ATTACK,//アタック中
	HIT,//接触中
	CONTACT,//発見中
	RIGHT,//右向いてる
	LIGHT//左向いてる
};
class Enemy :public Character
{
protected:
	int hp;
	bool isGround;
	bool isNoDamage;
private:
	bool isContact;
public:
	void Move();
	void HitCheck();
	void Attack();
	void Jump();
};

