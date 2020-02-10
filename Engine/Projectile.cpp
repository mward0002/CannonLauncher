#include "Projectile.h"



void Projectile::Init(const Vec2& pos_in, const Vec2& vel_in)
{
	pos = pos_in;
	vel = vel_in;
}

void Projectile::Draw(Graphics& gfx) const
{
	if (spawned) {
	gfx.DrawRect(pos.x, pos.x + width, pos.y, pos.y + height, color);
	}
	
}

void Projectile::Update(float dt)
{
	pos += vel * dt;
	
	vel.y -= g * dt;
	
	if (counter > counterMax) {


		spawned = false;
		counter = 0.0f;
	
	}
	
	
}

RectF Projectile::GetRect() const
{
	return RectF(pos.x, pos.x + width, pos.y, pos.y + height);
}

Vec2 Projectile::GetPos() const
{
	return pos;
}

bool Projectile::isSpawned() const
{
	return spawned;
}



void Projectile::SetPos(const Vec2& pos_in)
{
	pos = pos_in;
	
	spawned = true;
	
}

void Projectile::SetVel(const Vec2& vel_in)
{
	
	vel = vel_in;
}

void Projectile::increaseCounter(float dt)
{
	if (spawned) {
		counter += dt;
	}
	
}

void Projectile::ClampToScreen()
{
	if (GetRect().bottom >= Graphics::ScreenHeight) {
		pos.y -= 1;
		
		ReboundY();
		if (vel.y < -0.14) {
			vel.y *= 0.9f;
		}
	}
	else if (GetRect().top < 0) {
		pos.y += 1;
		ReboundY();
	
	}
	else if (GetRect().right >= Graphics::ScreenWidth) {
		pos.x -= 1;
		ReboundX();
		if (vel.x < -0.14) {
			vel.x *= 0.9f;
		}
	
	}
	else if (GetRect().left < 0) {
		pos.x += 1;
		ReboundX();
		if (vel.x > 0.14) {
			vel.x *= 0.9f;
		}
	}

}

void Projectile::ReboundY()
{
	vel.y *= -1;
}

void Projectile::ReboundX()
{
	vel.x *= -1;
}
