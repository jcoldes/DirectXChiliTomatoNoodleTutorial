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
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!inhibitUp)
		{
			vy -= 1;
			inhibitUp = true;
		}
	}
	else 
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!inhibitDown)
		{
			vy += 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) 
	{
		if (!inhibitLeft)
		{
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) 
	{
		if (!inhibitRight)
		{
			vx += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	x = x + vx;
	y = y + vy;

	if (x < 6) x = 6;
	if (x > 794) x = 794;

	if (y < 6) y = 6;
	if (y > 594) y = 594;

	if (wnd.kbd.KeyIsPressed('1')) red = red ? 0 : 255;
	if (wnd.kbd.KeyIsPressed('2')) green = green ? 0 : 255;
	if (wnd.kbd.KeyIsPressed('3')) blue = blue ? 0 : 255;
	toggle_rect = wnd.kbd.KeyIsPressed(VK_SPACE);
}

void Game::ComposeFrame()
{

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
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
	else 
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
	

}
