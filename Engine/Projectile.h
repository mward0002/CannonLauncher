#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "Hoop.h"
class Projectile {
public:
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	RectF GetRect() const;
	Vec2 GetPos() const;
	bool isSpawned() const;
	bool haveScored() const;
	void SetPos(const Vec2& pos_in);
	void SetVel(const Vec2& vel_in);
	void increaseCounter(float dt);
	void ClampToScreen();
	void Score(Hoop& hoop);
	
	void ReboundY();
	void ReboundX();
	void DoBBCollision(Hoop& hoop);
private:
	Vec2 pos;
	Vec2 vel;
	float counter = 0.0f;
	bool hasScored = false;
	bool canScore = true;
	float counterMax = 6.0f;
	bool spawned = false;
	float g = -800.0f;
	float height = 10.0f;
	float width = 10.0f;
	Color color = Colors::Red;
};