/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/

#pragma once


#include <SDL2/SDL.h>
#include "Collider.h"
#include "Rock.h"
#include <vector>


class Ship
{
public:
	int x, y;
	int velx;
	Collider collider;

	Ship();
	Ship(SDL_Texture* image);
	void Update();
	void Render(SDL_Renderer* renderer);

private:
	SDL_Texture* image;
	SDL_Rect srcRect;
};

