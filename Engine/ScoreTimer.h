#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Colors.h"
class ScoreTimer {
public:
	void Draw(Graphics& gfx);
	void decreaseTimer(float dt);
	bool stillAlive() const;
	void resetScoreTimer();
private:
	Vec2 pos{ 10.0f, 40.0f };
	Color color = Colors::Magenta;
	float height = 10.0f;
	float scalar = 15.0f;
	float timeToMakeShot = 15.0f;
};