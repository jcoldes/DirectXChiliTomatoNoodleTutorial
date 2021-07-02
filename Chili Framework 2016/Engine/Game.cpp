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
	gfx( wnd )
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
}

void Game::ComposeFrame()
{
	int x = 400;
	int y = 300;

	int red = 255;
	int green = 255;
	int blue = 255;

	bool toggle_rect = false;

	if (wnd.kbd.KeyIsPressed(VK_UP))	y = 250;
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))	y = 350;
	else y = 300;

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) x = 350;
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) x = 450;
	else x = 400;

	if (wnd.kbd.KeyIsPressed('1')) red = red == 255 ? 0 : 255;
	if (wnd.kbd.KeyIsPressed('2')) green = green == 255 ? 0 : 255;
	if (wnd.kbd.KeyIsPressed('3')) blue = blue == 255 ? 0 : 255;

	if (wnd.kbd.KeyIsPressed(VK_SPACE)) toggle_rect = !toggle_rect;


	if (toggle_rect)
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
