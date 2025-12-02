#include "Player.h"

void Player::Init()
{
	player.SetPos(0.0f, 0.0f, 0.0f);
}

void Player::Update()
{
}

void Player::Draw()
{
}

void Player::UnInit()
{
	
}

void Player::Move()
{
	DirectX::XMFLOAT3 pos= player.GetPos();

	if (input.GetKeyPress(VK_A))
	{
		player.SetPos(pos.x -= 1.0f, pos.y += 0.0f, pos.z += 0.0f);
	}
	if (input.GetKeyPress(VK_D))
	{
		player.SetPos(pos.x += 1.0f, pos.y += 0.0f, pos.z += 0.0f);
	}
}

void Player::Attack()
{

}

void Player::Blink()
{

}

void Player::Jump()
{
	DirectX::XMFLOAT3 pos = player.GetPos();
	if (input.GetKeyTrigger(VK_SPACE))
	{
		player.SetPos(pos.x += 0.0f, pos.y += 1.0f, pos.z += 0.0f);
	}
	
}

void Player::WallJump()
{

}

void Player::GetBlink()
{

}
