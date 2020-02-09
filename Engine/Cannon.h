#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Keyboard.h"
class Cannon {
public:
	Cannon(Vec2 pos_in);
	void Draw(Graphics& gfx);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
	void ClipToScreen(); 
	Vec2 GetPos() const;
private:
	const Color cannonColor = Colors::LightGray;
	const Color wheelColor = Colors::Gray;
	static constexpr float cannonWidth = 60.0f;
	static constexpr float cannonHeight = 20.0f;
	static constexpr float wheelWidth = 10.0f;
	static constexpr float wheelHeight = 10.0f;
	static constexpr float wheelGap =  15.0f;
	Vec2 pos;
	Vec2 vel{ 50.0f, 0.0f };
};