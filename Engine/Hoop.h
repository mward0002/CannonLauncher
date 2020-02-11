#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"

class Hoop {
public:
	Hoop(Vec2& pos_in);
	void Draw(Graphics& gfx);
	RectF GetBBRect();
	RectF GetHoopRect();
	RectF GetCollidableHoopRect();

private:
	Vec2 pos;
	static constexpr int hoopHeight = 10;
	static constexpr int hoopWidth = 50;
	static constexpr int bbHeight = 60;
	static constexpr int bbWidth = 10;
	const Color backboardColor = Colors::White;
	const Color hoopColor = Colors::Yellow;
};