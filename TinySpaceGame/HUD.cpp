#include "HUD.h"

#include <sstream>
#include <string.h>


void HUD::Init(SDL_Renderer* renderer)
{
	TTF_Init();
	this->font = TTF_OpenFont("cre.fon", 12);
	this->fontColor = { 255, 255, 255 };

	SDL_Surface *tmpSurf = TTF_RenderText_Solid(this->font, "YOU DED", this->fontColor);
	this->dedMessage = SDL_CreateTextureFromSurface(renderer, tmpSurf);
	SDL_FreeSurface(tmpSurf);

	tmpSurf = TTF_RenderText_Solid(this->font, "[space]", this->fontColor);
	this->restartMessage = SDL_CreateTextureFromSurface(renderer, tmpSurf);
	SDL_FreeSurface(tmpSurf);
}

void HUD::Render(SDL_Renderer* renderer)
{
	SDL_Rect destRect = { 32, 100, 32 * 6, 32 };
	SDL_RenderCopy(renderer, this->dedMessage, NULL, &destRect);

	destRect = { 66, 140, 16 * 7, 16 };
	SDL_RenderCopy(renderer, this->restartMessage, NULL, &destRect);
}

void HUD::Clean()
{
	TTF_Quit();
}