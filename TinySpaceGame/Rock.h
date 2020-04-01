/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/

#include <SDL2/SDL.h>
#include "Collider.h"
#include <vector>

#pragma once
class Rock
{
public:
	int x, y;
	Collider collider;

	Rock();
	Rock(SDL_Texture *image, int size = 8);
	void Update();
	void Reset();
	void Render(SDL_Renderer *renderer);

private:
	SDL_Texture* image;
	SDL_Rect srcRect;
	int size;
};

