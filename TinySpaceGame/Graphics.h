/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/


#pragma once

#include <SDL2/SDL.h>

class Graphics
{
public:
	void Init(const char* windowTitle, int windowWidth, int windowHeight);
	void Clean();
	void Clear();
	void FlipBuffers();

	SDL_Texture* sheet;

	SDL_Renderer* renderer;

private:
	SDL_Window* window;

};

