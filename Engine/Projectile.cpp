#include "Projectile.h"
#include <cmath>


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

bool Projectile::haveScored() const
{
	return hasScored;
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
		pos.y -= 3;
		
		ReboundY();
		if (vel.y < -0.14) {
			vel.y *= 0.9f;
		}
	}
	else if (GetRect().top < 0) {
		pos.y += 3;
		ReboundY();
	
	}
	else if (GetRect().right >= Graphics::ScreenWidth) {
		pos.x -= 3;
		ReboundX();
		if (vel.x < -0.14) {
			vel.x *= 0.9f;
		}
	
	}
	else if (GetRect().left < 0) {
		pos.x += 3;
		ReboundX();
		if (vel.x > 0.14) {
			vel.x *= 0.9f;
		}
	}

}

void Projectile::Score(Hoop& hoop)
{
	RectF bbRect = hoop.GetBBRect();
	RectF collidableHoop = hoop.GetCollidableHoopRect();
	int leftBoundry = bbRect.left + 3;
	int rightBoundry = collidableHoop.right - 3;
	int topBoundry = collidableHoop.top;
	int bottomBoundry = collidableHoop.bottom;
	Vec2 center = GetRect().GetCenter();
	if (vel.y < 0 && center.x > rightBoundry && center.x < leftBoundry && center.y < bottomBoundry && center.y > topBoundry) {
	
		canScore = false;
	
	}
	if (vel.y > 0 && center.x > rightBoundry && center.x < leftBoundry && center.y < bottomBoundry && center.y > topBoundry && canScore) {
	
		hasScored = true;
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

void Projectile::DoBBCollision(Hoop& hoop)
{
	RectF bbRect = hoop.GetBBRect();
	RectF collidableRim = hoop.GetCollidableHoopRect();
	if (GetRect().IsOverlaping(bbRect)) {
		
		 if (pos.x >= bbRect.left && pos.x <= bbRect.right)
		{
			ReboundY();
		}
		else
		{
			ReboundX();
		}
	
	}

	if (GetRect().IsOverlaping(collidableRim)) {
		
		if (pos.x >= collidableRim.left && pos.x <= collidableRim.right)
		{
			ReboundY();
		}
		else
		{
			ReboundX();
		}

	}

}
