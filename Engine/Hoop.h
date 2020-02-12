#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include <random>
class Hoop {
public:
	Hoop(Vec2& pos_in);
	void Draw(Graphics& gfx);
	RectF GetBBRect();
	RectF GetHoopRect();
	RectF GetCollidableHoopRect();
	RectF GetWholeRect();
	void ReboundY();
	void ReboundX();
	void Update(float dt);
	void increaseCounter(float dt);
	void GenerateNewVel();
	void ClampToScreen();
private:
	float velScalar = 80.0f;
	Vec2 pos;
	Vec2 vel{ 0.0f, 0.0f };
	float counter = 0.0f;
	float counterMax = 3.0f;
	static constexpr int hoopHeight = 10;
	static constexpr int hoopWidth = 50;
	static constexpr int bbHeight = 60;
	static constexpr int bbWidth = 10;
	const Color backboardColor = Colors::White;
	const Color hoopColor = Colors::Yellow;
};