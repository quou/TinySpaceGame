/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/


#include <ctime>
#include <cstdlib>


#include "Game.h"


int main(int argc, char** argv)
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	srand(time(NULL));
	Game game;

	game.Init();

	while (game.Running)
	{
		frameStart = SDL_GetTicks();

		game.HandleEvents();
		game.Update();
		game.Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game.Quit();

	return 1;
}