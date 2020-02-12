/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	lIndicator( lIndicatorPos),
	cannon(cannonPos),
	hoop(hoopPos)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	const float frameT = ft.FrameTime() / float(nSubframes);
	for (int f = 0; f < nSubframes; f++)
	{
		UpdateModel(frameT);
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float ft)
{
	const float dt = ft;
	cannon.Update(wnd.kbd, dt);
	cannon.ClipToScreen();
	if (wnd.mouse.LeftIsPressed())
	{
		launchFactor += launchPowerUpFactor * dt;
		
	}
	while (!wnd.mouse.IsEmpty())
	{
		const Mouse::Event e = wnd.mouse.Read();
		if (e.GetType() == Mouse::Event::Type::LRelease)
		{
			// respond to left mouse click event
			Vec2 mouseDir = { (float) e.GetPosX(), (float)e.GetPosY() };
			Vec2 pos = cannon.GetPos() + Vec2{60.0f, 5.0f};
			projectiles[nNumberProjectiles].SetPos(pos);
			Vec2 velDir = mouseDir - projectiles[nNumberProjectiles].GetPos();
			projectiles[nNumberProjectiles].SetVel(velDir.Normalize() * launchFactor);
			nNumberProjectiles++;
			launchFactor = minLaunchFactor;
		}
	}
	int tempScore = 0;
	for (int i = 0; i < nNumberProjectiles + 1; i++) {
		if (projectiles[i].isSpawned()) 
		{
			projectiles[i].increaseCounter(dt);
			projectiles[i].Update(dt);
			projectiles[i].ClampToScreen();
			projectiles[i].DoBBCollision(hoop);
			projectiles[i].Score(hoop);
		}
		if (projectiles[i].haveScored()) {
		
			tempScore++;
		}
	
	}
	
	score = tempScore;
	hoop.increaseCounter(dt);
	hoop.Update(dt);
	hoop.ClampToScreen();
	
}

void Game::ComposeFrame()
{
	gfx.DrawRect(200, 200 + score * 10, 15, 30, color);
	lIndicator.Draw(gfx, launchFactor - minLaunchFactor);
	cannon.Draw(gfx);
	for (int i = 0; i < nNumberProjectiles + 1; i++) {
		projectiles[i].Draw(gfx);
	}
	hoop.Draw(gfx);
}
