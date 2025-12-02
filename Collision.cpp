#include "Collision.h"
#include "HewStd.h"

ColRes CollisionRect(const Object& a, const Object& b)
{
	ColRes colres{ false, ColDir::NONE };

	// オブジェクトの座標とサイズを取得
	hstd::MakeFloat2 aPos = a.GetPos();
	hstd::MakeFloat2 bPos = b.GetPos();
	hstd::MakeFloat2 aSize = a.GetSize();
	hstd::MakeFloat2 bSize = b.GetSize();

	// AABB外側判定（衝突していない場合）
	if (aPos.x >= bPos.x + bSize.x ||    // aがbの右側
		aPos.x + aSize.x <= bPos.x ||    // aがbの左側
		aPos.y >= bPos.y + bSize.y ||    // aがbの下側
		aPos.y + aSize.y <= bPos.y)      // aがbの上側
	{
		return colres; // 当たっていので早期リターン
	}

//---- 当たっている場合の処理 -------------------------------//
	colres.hit = true; // 接触している
	
	// 接触方向の計算
	// どれくらい重なっているかを計算
	float overlapLeft = (aPos.x + aSize.x) - bPos.x;	// 左側に
	float overlapRight = (bPos.x + bSize.x) - aPos.x;	// 右側に
	float overlapTop = (aPos.y + aSize.y) - bPos.y;		// 上側に
	float overlapBottom = (bPos.y + bSize.y) - aPos.y;	// 下側に

	float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });


	if (minOverlap == overlapLeft)			colres.dir = ColDir::LEFT;		// 一番重なりが少ないのが左なら左
	else if (minOverlap == overlapRight)	colres.dir = ColDir::RIGHT;		// 一番重なりが少ないのが右なら右
	else if (minOverlap == overlapTop)		colres.dir = ColDir::TOP;		// 一番重なりが少ないのが上なら上
	else if (minOverlap == overlapBottom)	colres.dir = ColDir::BOTTOM;	// 一番重なりが少ないのが下なら下
	else									colres.dir = ColDir::NONE;		// 一番重なりが少ないのが同じならなし
	
	return colres;  // 当たっている状態を返す
}

ColRes CollisionRect(const Object& a, hstd::MakeFloat2& bPos, const hstd::MakeFloat2& bSize)
{

	ColRes colres;
	colres.hit = false;
	colres.dir = ColDir::NONE;

	hstd::MakeFloat2 aPos = a.GetPos();
	hstd::MakeFloat2 aSize = a.GetSize();

	// AABB外側判定（衝突していない場合）
	if (aPos.x >= bPos.x + bSize.x ||    // aがbの右側
		aPos.x + aSize.x <= bPos.x ||    // aがbの左側
		aPos.y >= bPos.y + bSize.y ||    // aがbの下側
		aPos.y + aSize.y <= bPos.y)      // aがbの上側
	{
		return colres; // 当たっていので早期リターン
	}

	//---- 当たっている場合の処理 -------------------------------//
	colres.hit = true; // 接触している

	// 接触方向の計算
	// どれくらい重なっているかを計算
	float overlapLeft = (aPos.x + aSize.x) - bPos.x;	// 左側に
	float overlapRight = (bPos.x + bSize.x) - aPos.x;	// 右側に
	float overlapTop = (aPos.y + aSize.y) - bPos.y;		// 上側に
	float overlapBottom = (bPos.y + bSize.y) - aPos.y;	// 下側に

	float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });


	if (minOverlap == overlapLeft)			colres.dir = ColDir::LEFT;		// 一番重なりが少ないのが左なら左
	else if (minOverlap == overlapRight)	colres.dir = ColDir::RIGHT;		// 一番重なりが少ないのが右なら右
	else if (minOverlap == overlapTop)		colres.dir = ColDir::TOP;		// 一番重なりが少ないのが上なら上
	else if (minOverlap == overlapBottom)	colres.dir = ColDir::BOTTOM;	// 一番重なりが少ないのが下なら下
	else									colres.dir = ColDir::NONE;		// 一番重なりが少ないのが同じならなし

	return colres;  // 当たっている状態を返す
}

ColRes CollisionRect(const hstd::MakeFloat2& aPos, const hstd::MakeFloat2& aSize, const hstd::MakeFloat2& bPos, const hstd::MakeFloat2& bSize)
{
	ColRes colres;
	colres.hit = false;
	colres.dir = ColDir::NONE;

	// AABB外側判定（衝突していない場合）
	if (aPos.x >= bPos.x + bSize.x ||    // aがbの右側
		aPos.x + aSize.x <= bPos.x ||    // aがbの左側
		aPos.y >= bPos.y + bSize.y ||    // aがbの下側
		aPos.y + aSize.y <= bPos.y)      // aがbの上側
	{
		return colres; // 当たっていので早期リターン
	}

	//---- 当たっている場合の処理 -------------------------------//
	colres.hit = true; // 接触している

	// 接触方向の計算
	// どれくらい重なっているかを計算
	float overlapLeft = (aPos.x + aSize.x) - bPos.x;	// 左側に
	float overlapRight = (bPos.x + bSize.x) - aPos.x;	// 右側に
	float overlapTop = (aPos.y + aSize.y) - bPos.y;		// 上側に
	float overlapBottom = (bPos.y + bSize.y) - aPos.y;	// 下側に

	float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });


	if (minOverlap == overlapLeft)			colres.dir = ColDir::LEFT;		// 一番重なりが少ないのが左なら左
	else if (minOverlap == overlapRight)	colres.dir = ColDir::RIGHT;		// 一番重なりが少ないのが右なら右
	else if (minOverlap == overlapTop)		colres.dir = ColDir::TOP;		// 一番重なりが少ないのが上なら上
	else if (minOverlap == overlapBottom)	colres.dir = ColDir::BOTTOM;	// 一番重なりが少ないのが下なら下
	else									colres.dir = ColDir::NONE;		// 一番重なりが少ないのが同じならなし

	return colres;  // 当たっている状態を返す
}
