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
