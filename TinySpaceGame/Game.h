/* TinySpaceGame
	by George Lamb
	started: 1/04/2020
*/

#include "Graphics.h"

#pragma once
class Game
{
public:
	bool Running;

	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Quit();

private:
	Graphics graphics;
};

