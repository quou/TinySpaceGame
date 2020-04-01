/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/

#include "Rock.h"

#include "random.h"

#include <iostream>

Rock::Rock()
{
}

Rock::Rock(SDL_Texture* image, int size)
{
	this->size = size;
	if (size == 1)
	{
		this->x = Random(0, 256);
		this->y = Random(0, 256);
	}
	else
	{
		this->Reset();
	}


	this->collider.w = 16;
	this->collider.h = 16;
	this->srcRect = { 8, 0, size, size };
	this->image = image;
}

void Rock::Update()
{
	this->collider.x = this->x;
	this->collider.y = this->y;

	if (this->size != 1)
		this->y += 2;
	else
		this->y += 1;

	if (this->y >= 256)
	{
		this->Reset();
	}
}

void Rock::Reset()
{
	this->x = Random(0, 256);
	this->y = Random(-256, -16);
}

void Rock::Render(SDL_Renderer* renderer)
{
	SDL_Rect destRect;
	if (this->size != 1)
		destRect = { this->x, this->y, 16, 16 };
	else
		destRect = { this->x, this->y, 1, 1 };

	SDL_RenderCopy(renderer, this->image, &this->srcRect, &destRect);
}
