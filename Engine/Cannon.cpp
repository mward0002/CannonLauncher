#include "Cannon.h"

Cannon::Cannon(Vec2 pos_in)
	:
	pos(pos_in)
{
	
}

void Cannon::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.x + cannonWidth, pos.y, pos.y + cannonHeight, cannonColor);
	gfx.DrawRect(pos.x, pos.x + wheelWidth, pos.y + cannonHeight, pos.y + cannonHeight + wheelHeight, wheelColor);
	gfx.DrawRect(pos.x + wheelWidth + wheelGap, pos.x + 2 * wheelWidth + wheelGap , pos.y + cannonHeight, pos.y + cannonHeight + wheelHeight, wheelColor);
}

void Cannon::Update(const Keyboard& kbd, float dt)
{
	Vec2 dir = { 400.0f, 0 };
	if (kbd.KeyIsPressed('A')) {
		pos -= dir * dt;
	
	}
	else if (kbd.KeyIsPressed('D')) {

		pos += dir * dt;
	}
}

RectF Cannon::GetRect() const
{
	return RectF(pos.x, pos.x + cannonWidth, pos.y, pos.y + cannonHeight);
}

void Cannon::ClipToScreen()
{
	if (GetRect().left <= 0) {
	
		pos += {1.0f, 0};
	}
	if (GetRect().right >= Graphics::ScreenWidth) {
	
		pos -= {1.0f, 0};
	}
}

Vec2 Cannon::GetPos() const
{
	return pos;
}
