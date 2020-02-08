#include "Projectile.h"



void Projectile::Init(const Vec2& pos_in, const Vec2& vel_in)
{
	pos = pos_in;
	vel = vel_in;
}

void Projectile::Draw(Graphics& gfx) const
{
	gfx.DrawRect(pos.x, pos.x + width, pos.y, pos.y + height, color);
}

void Projectile::Update()
{
	pos += vel;
	
		vel.y -= g;
	
	
	
	if (GetRect().bottom >= Graphics::ScreenHeight ) {
		ReboundY();
		if (vel.y < -0.14) {
			vel.y += 0.07f;
		}
		
		
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

void Projectile::SetPos(const Vec2& pos_in)
{
	pos = pos_in;
	
}

void Projectile::SetVel(const Vec2& vel_in)
{
	
	vel = vel_in;
}

void Projectile::ReboundY()
{
	vel.y *= -1;
}

void Projectile::ReboundX()
{
	vel.x *= -1;
}
