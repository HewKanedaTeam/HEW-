#pragma once
#include "HewStd.h"
#include "Object.h"

// 衝突方向
enum class ColDir
{
	NONE,	// なし
	TOP,	// 上から
	BOTTOM,	// 下から
	LEFT,	// 左から
	RIGHT	// 右から
};

// 衝突したかと衝突方向
struct ColRes
{
	bool hit;
	ColDir dir;
};

//長方形(AABB)での接触判定、返り値はbool型の接触しているか、enumでAがBに接触した方向
ColRes CollisionRect(const Object& a, const Object& b); // オブジェクト同士の判定
ColRes CollisionRect(const Object& a, MakeFloat2& bPos, const MakeFloat2& bSize); // オブジェクトと座標・サイズで判定
ColRes CollisionRect(const MakeFloat2& aPos, const MakeFloat2& aSize, const MakeFloat2& bPos, const MakeFloat2& bSize); // 座標・サイズ同士で判定