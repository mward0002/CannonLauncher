#include "Hoop.h"

Hoop::Hoop(Vec2& pos_in)
	:
	pos(pos_in)
{
}

void Hoop::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.x + bbWidth, pos.y, pos.y + bbHeight, backboardColor);
	gfx.DrawRect(pos.x - hoopWidth, pos.x, pos.y + bbHeight - hoopHeight , pos.y + bbHeight, hoopColor);
	gfx.DrawRect(pos.x - hoopWidth, pos.x - hoopWidth + 6, pos.y + bbHeight - hoopHeight, pos.y + bbHeight, Colors::Green);
}

RectF Hoop::GetBBRect()
{
	return RectF(pos.x, pos.x + bbWidth, pos.y, pos.y + bbHeight);
}

RectF Hoop::GetHoopRect()
{
	return RectF(pos.x - hoopWidth, pos.x, pos.y + bbHeight - hoopHeight, pos.y + bbHeight );
}

RectF Hoop::GetCollidableHoopRect()
{
	return RectF(pos.x - hoopWidth, pos.x - hoopWidth + 6, pos.y + bbHeight - hoopHeight, pos.y + bbHeight);
}

RectF Hoop::GetWholeRect()
{
	return RectF(pos.x - hoopWidth, pos.x + bbWidth, pos.y, pos.y + bbHeight);
}

void Hoop::ReboundY()
{
	vel.y = -vel.y;
}

void Hoop::ReboundX()
{
	vel.x = -vel.x;
}

void Hoop::Update(float dt)
{
	pos += vel * dt;
	if (counter > counterMax) 
	{
		GenerateNewVel();
		counter = 0.0f;
	}
}

void Hoop::increaseCounter(float dt)
{
	counter += dt;
}

void Hoop::GenerateNewVel()
{
	std::random_device rd;
	std::mt19937 rng( rd() );
	std::uniform_int_distribution<int> xDir(-51, 51);
	std::uniform_int_distribution<int> yDir(-51, 51);
	vel.x = xDir(rng);
	vel.y = yDir(rng);
	vel.Normalize();
	vel = vel * velScalar;
}

void Hoop::ClampToScreen()
{
	if (GetWholeRect().bottom >= Graphics::ScreenHeight) {
		pos.y -= 3;

		ReboundY();
		
	}
	else if (GetWholeRect().top < 0) {
		pos.y += 3;
		ReboundY();

	}
	else if (GetWholeRect().right >= Graphics::ScreenWidth) {
		pos.x -= 3;
		ReboundX();
		

	}
	else if (GetWholeRect().left < 0) {
		pos.x += 3;
		ReboundX();
		
	}
}
