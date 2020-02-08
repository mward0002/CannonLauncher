#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
class Projectile {
public:
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Update();
	RectF GetRect() const;
	Vec2 GetPos() const;
	void SetPos(const Vec2& pos_in);
	void SetVel(const Vec2& vel_in);
	void ReboundY();
	void ReboundX();
private:
	Vec2 pos;
	Vec2 vel;
	float g = -.0007;
	float height = 10.0f;
	float width = 10.0f;
	Color color = Colors::Red;
};