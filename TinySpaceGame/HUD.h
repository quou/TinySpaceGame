#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class HUD
{
public:
	void Init(SDL_Renderer* renderer);
	void Render(SDL_Renderer* renderer);
	void Clean();

private:
	TTF_Font *font;
	SDL_Color fontColor;
	SDL_Texture* dedMessage;
	SDL_Texture* restartMessage;
};

