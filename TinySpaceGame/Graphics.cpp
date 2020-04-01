/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/


#include "Graphics.h"

#include <SDL2/SDL_image.h>

#include <iostream>


void Graphics::Init(const char* windowTitle, int windowWidth, int windowHeight)
{
	SDL_CreateWindowAndRenderer(windowWidth, windowHeight, NULL, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, windowTitle);

	SDL_Surface *tmpSurf = IMG_Load("MySheet.png");
	this->sheet = SDL_CreateTextureFromSurface(this->renderer, tmpSurf);
	SDL_FreeSurface(tmpSurf);

}

void Graphics::Clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
}

void Graphics::Clear()
{
	SDL_RenderClear(this->renderer);
}

void Graphics::FlipBuffers()
{
	SDL_RenderPresent(this->renderer);
}