#include "Enemy.h"

void Enemy::Init()
{
    Enemy.SetPos(0.0f, 0.0f, 0.0f);
    state = LEFT;          // 初期状態：左向き
    hp = 1;
    speed = 1.0f;
    gravity = 0.5f;
    isGround = true;
    isNoDamage = false;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}

void Enemy::UnInit()
{
}

void Enemy::Move()
{
    DirectX::XMFLOAT3 pos = Enemy.GetPos();
    // 状態に応じて左右へ移動
    switch (state)
    {
    case LEFT:
        Enemy.SetPos(pos.x -= speed, pos.y = 0, pos.z += 0.0f);
        break;

    case RIGHT:
        Enemy.SetPos(pos.x += speed, pos.y = 0, pos.z += 0.0f);
        break;

    default:
        break;
    }

    // 画面端で反転（例0～100の間を往復）
    if (pos.x < 0)
    {
        state = RIGHT; // 右へ向き直す
    }
    else if (pos.x > 100)
    {
        state = LEFT; // 左へ向き直す
    }
}

void Enemy::Attack()
{

}

void Enemy::Jump()
{
    DirectX::XMFLOAT3 pos = Enemy.GetPos();
    // 地面にいるときだけジャンプ
    if (isGround)
    {
        // ジャンプの初速
        Enemy.SetPos(pos.x=.0f, pos.y +=10.0f, pos.z += 0.0f);
        isGround = false;
        return;
    }

    //空中なら落下処理
    Enemy.SetPos(pos.x = 0.0f, pos.y -= gravity, pos.z += 0.0f);


    //地面の座標まで落ちると止まる
    if (pos.y >= 300)
    {
        Enemy.SetPos(pos.x = 0.0f, pos.y =300 , pos.z += 0.0f);
        isGround = true;
    }
}
