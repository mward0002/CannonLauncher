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
