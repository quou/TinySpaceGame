/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/

#include "Ship.h"
#include <iostream>

Ship::Ship()
{}

Ship::Ship(SDL_Texture* image)
{
	this->x = 115;
	this->y = 200;
	this->velx = 0;
	this->image = image;
	this->srcRect = { 0, 0, 8, 8 };
	this->collider = Collider(0, 0, 16, 14);
}

void Ship::Update()
{
	this->collider.x = this->x;
	this->collider.y = this->y;

	this->x += velx;


	if (this->x > 256)
	{
		this->x = 0;
	}
	else if (this->x < 0)
	{
		this->x = 254;
	}
}

void Ship::Render(SDL_Renderer* renderer)
{
	SDL_Rect destRect = { this->x, this->y, 16, 16 };
	SDL_RenderCopy(renderer, this->image, &this->srcRect, &destRect);
}