/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/

#include "Game.h"

#include "Ship.h"
#include "Rock.h"
#include "HUD.h"

#include <vector>

Ship player;
bool playerdead = false;
HUD hud;
std::vector<Rock> rocks;
std::vector<Rock> stars;



void Game::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	this->graphics.Init("TinySpaceGame", 256, 256);
	hud.Init(this->graphics.renderer);
	player = Ship(this->graphics.sheet);

	for (int i = 0; i < 25; i++)
	{
		Rock* rock = new Rock(this->graphics.sheet);
		rocks.push_back(*rock);
		delete rock;
	}

	for (int i = 0; i < 100; i++)
	{
		Rock* star = new Rock(this->graphics.sheet, 1);
		stars.push_back(*star);
		delete star;
	}
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
	{
		this->Running = false;
	}

	if (!playerdead)
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				player.velx = -2;
				break;
			case SDLK_RIGHT:
				player.velx = 2;
				break;
			default:
				break;
			}
		}

		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				player.velx = 0;
				break;
			case SDLK_RIGHT:
				player.velx = 0;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
		{
			for (auto& r : rocks)
			{
				r.Reset();
			}
			player.velx = 0;
			playerdead = false;
		}
	}
}

void Game::Update()
{
	if (!playerdead)
	{
		player.Update();


		for (auto& r : rocks)
		{
			r.Update();

			if (r.collider.MeetingCheck(player.collider))
			{
				playerdead = true;
			}
		}

		for (auto& s : stars)
		{
			s.Update();
		}
	}
}

void Game::Render()
{
	this->graphics.Clear();

	// stuff to render goes here
	if (!playerdead)
	{
		player.Render(this->graphics.renderer);

		for (auto& r : rocks)
		{
			r.Render(this->graphics.renderer);
		}

		for (auto& s : stars)
		{
			s.Render(this->graphics.renderer);
		}
	}
	else
	{
		hud.Render(this->graphics.renderer);
	}

	this->graphics.FlipBuffers();
}

void Game::Quit()
{
	this->graphics.Clean();
	SDL_Quit();
}
