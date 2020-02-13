#include "ScoreTimer.h"

void ScoreTimer::Draw(Graphics & gfx)
{
	gfx.DrawRect(pos.x, pos.x + timeToMakeShot * scalar, pos.y, pos.y + height, color);
}

void ScoreTimer::decreaseTimer(float dt)
{
	timeToMakeShot -= dt;
}

bool ScoreTimer::stillAlive() const
{
	return timeToMakeShot >= 0;
}

void ScoreTimer::resetScoreTimer()
{
	timeToMakeShot = 15.0f;
}
