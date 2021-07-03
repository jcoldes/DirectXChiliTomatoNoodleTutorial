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

Game::Game( MainWindow& wnd ) : wnd( wnd ), gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))	y_mobile -= 1;
	if (wnd.kbd.KeyIsPressed(VK_DOWN))	y_mobile += 1;
	if (wnd.kbd.KeyIsPressed(VK_LEFT))	x_mobile -= 1;
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) x_mobile += 1;

	y_mobile = ClampScreen(y_mobile, 5, gfx.ScreenHeight);
	x_mobile = ClampScreen(x_mobile, 5, gfx.ScreenHeight);
	
	colliding = OverlapTest(x_fixed, y_fixed, x_mobile, y_mobile);
}

void Game::ComposeFrame()
{
	DrawBox(x_fixed, y_fixed, 0, 255, 0);

	int r_mobile, g_mobile, b_mobile;
	if (colliding) 
	{
		DrawBox(x_mobile, y_mobile, 255, 0, 0);
	}
	else
	{
		DrawBox(x_mobile, y_mobile, 255, 255, 255);
	}
}

void Game::DrawBox(int x, int y, int red, int green, int blue)
{
	gfx.PutPixel(x + 5, y + 5, red, green, blue);
	gfx.PutPixel(x + 4, y + 5, red, green, blue);
	gfx.PutPixel(x + 3, y + 5, red, green, blue);
	gfx.PutPixel(x + 5, y + 4, red, green, blue);
	gfx.PutPixel(x + 5, y + 3, red, green, blue);
	gfx.PutPixel(x - 5, y + 5, red, green, blue);
	gfx.PutPixel(x - 4, y + 5, red, green, blue);
	gfx.PutPixel(x - 3, y + 5, red, green, blue);
	gfx.PutPixel(x - 5, y + 4, red, green, blue);
	gfx.PutPixel(x - 5, y + 3, red, green, blue);
	gfx.PutPixel(x + 5, y - 5, red, green, blue);
	gfx.PutPixel(x + 4, y - 5, red, green, blue);
	gfx.PutPixel(x + 3, y - 5, red, green, blue);
	gfx.PutPixel(x + 5, y - 4, red, green, blue);
	gfx.PutPixel(x + 5, y - 3, red, green, blue);
	gfx.PutPixel(x - 5, y - 5, red, green, blue);
	gfx.PutPixel(x - 4, y - 5, red, green, blue);
	gfx.PutPixel(x - 3, y - 5, red, green, blue);
	gfx.PutPixel(x - 5, y - 4, red, green, blue);
	gfx.PutPixel(x - 5, y - 3, red, green, blue);
}

void Game::DrawCrossHair(int x, int y, int red, int green, int blue)
{
	gfx.PutPixel(x - 5, y, red, green, blue);
	gfx.PutPixel(x - 4, y, red, green, blue);
	gfx.PutPixel(x - 3, y, red, green, blue);
	gfx.PutPixel(x + 3, y, red, green, blue);
	gfx.PutPixel(x + 4, y, red, green, blue);
	gfx.PutPixel(x + 5, y, red, green, blue);
	gfx.PutPixel(x, y - 5, red, green, blue);
	gfx.PutPixel(x, y - 4, red, green, blue);
	gfx.PutPixel(x, y - 3, red, green, blue);
	gfx.PutPixel(x, y + 3, red, green, blue);
	gfx.PutPixel(x, y + 4, red, green, blue);
	gfx.PutPixel(x, y + 5, red, green, blue);
}

bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
{
	const int left_mobile = box0x - 5;
	const int right_mobile = box0x + 5;
	const int top_mobile = box0y - 5;
	const int bottom_mobile = box0y + 5;

	const int left_fixed = box1x - 5;
	const int right_fixed = box1x + 5;
	const int top_fixed = box1y - 5;
	const int bottom_fixed = box1y + 5;

	return left_mobile <= right_fixed &&
		   right_mobile >= left_fixed &&
		   top_mobile <= bottom_fixed &&
		   bottom_mobile >= top_fixed;
}

int Game::ClampScreen(int input, int radius, int limit)
{
	if (input - radius <= 0)
		return 0 + radius;
	else if (input + radius >= limit)
		return limit - radius;
	else 
		return input;
}