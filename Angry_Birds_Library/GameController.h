#pragma once

#ifndef ANGRY_BIRDS_GAME_CONTROLLER_H
#define ANGRY_BIRDS_GAME_CONTROLLER_H

#include "cyclone.h"
#include "raylib.h"

class Game_Controller
{
public:
	void restart();

	void fixedTick(cyclone::real _dt);

	void processInput();
};

#endif // ANGRY_BIRDS_GAME_CONTROLLER_H