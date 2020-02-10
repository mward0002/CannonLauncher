#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
class LaunchStrengthIndicator {
public:
	LaunchStrengthIndicator(Vec2& pos_in);
	void Draw(Graphics& gfx, float width);
private:
	Vec2 pos;
	Color color = Colors::Cyan;
	int height = 15;
};