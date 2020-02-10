#include "LaunchStrengthIndicator.h"

LaunchStrengthIndicator::LaunchStrengthIndicator(Vec2& pos_in)
	:
	pos(pos_in)
{
}

void LaunchStrengthIndicator::Draw(Graphics& gfx, float width)
{
	int intWidth = (int)width;
	RectF thisRect = RectF(pos, intWidth / 10, height);

	if (intWidth / 10 + pos.x < Graphics::ScreenWidth) {
		gfx.DrawRect(thisRect, color);
	}
	
}
