#pragma once

#include <random>

int Random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}