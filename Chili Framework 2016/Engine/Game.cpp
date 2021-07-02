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
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) 	x_mobile -= 1;
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) x_mobile += 1; 

	if (x_mobile - 5 < 0)
	{
		x_mobile = 5;
	}
	if (x_mobile + 6 >= gfx.ScreenWidth)
	{
		x_mobile = gfx.ScreenWidth - 6;
	}

	if (y_mobile - 5 < 0)
	{
		y_mobile = 5;
	}
	if (y_mobile + 6 >= gfx.ScreenHeight)
	{
		y_mobile = gfx.ScreenHeight - 6;
	}

	const int left_mobile = x_mobile - 5;
	const int right_mobile = x_mobile + 5;
	const int top_mobile = y_mobile - 5;
	const int bottom_mobile = y_mobile + 5;

	const int left_fixed = x_fixed - 5;
	const int right_fixed = x_fixed + 5;
	const int top_fixed = y_fixed - 5;
	const int bottom_fixed = y_fixed + 5;

	if (left_mobile < right_fixed &&
		right_mobile > left_fixed &&
		top_mobile < bottom_fixed &&
		bottom_mobile > top_fixed)
	{
		colliding = true;
	}
	else
	{
		colliding = false;
	}
	toggle_rect = wnd.kbd.KeyIsPressed(VK_SPACE);
}

void Game::ComposeFrame()
{
	const int r_fixed = 0;
	const int g_fixed = 255;
	const int b_fixed = 0;

	gfx.PutPixel(x_fixed + 5, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 4, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 3, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 3, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 4, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 3, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed + 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed + 3, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 4, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 3, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 3, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 4, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 3, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed - 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed - 3, r_fixed, g_fixed, b_fixed);

	int r_mobile, g_mobile, b_mobile;
	if (colliding) 
	{
		r_mobile = 255;
		g_mobile = 0;
		b_mobile = 0;
	}
	else
	{
		r_mobile = g_mobile = b_mobile = 255;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		gfx.PutPixel(x_mobile + 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
	} 
	else 
	{
		gfx.PutPixel(x_mobile - 5,  y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 4,  y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 3,  y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 3,  y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 4,  y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 5,  y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile,		y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile,		y_mobile - 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile,		y_mobile - 3, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile,		y_mobile + 3, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile,		y_mobile + 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile,		y_mobile + 5, r_mobile, g_mobile, b_mobile);
	}
	

}
