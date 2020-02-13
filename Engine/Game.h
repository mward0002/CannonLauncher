/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Cannon.h"
#include "Vec2.h"
#include "FrameTimer.h"
#include "Projectile.h"
#include "LaunchStrengthIndicator.h"
#include "Hoop.h"
#include "ScoreTimer.h"
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float ft);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables 
	*/
	static constexpr int nSubframes = 10;
	static constexpr int nProjMax = 500;
	float launchFactor = 500.0f;
	float launchPowerUpFactor = 600.0f;
	static constexpr float minLaunchFactor = 500.0f;
	int nNumberProjectiles = 0;
	int score = 0;
	Vec2 cannonPos{0.0f, Graphics::ScreenHeight - 31.0f, };
	Cannon cannon;
	FrameTimer ft;
	Color color = Colors::Red;
	Projectile projectiles[nProjMax];
	Vec2 lIndicatorPos{ 10.0f, 10.0f };
	LaunchStrengthIndicator lIndicator;
	Vec2 hoopPos{ 500.0f, 200.0f };
	Hoop hoop;
	ScoreTimer scoreTimer;
	int checkForBucket = 0;
	
	/********************************/
};