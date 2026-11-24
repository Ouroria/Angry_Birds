#pragma once
#ifndef ANGRY_BIRDS_GAME_STATE_MACHINE_H
#define ANGRY_BIRDS_GAME_STATE_MACHINE_H

#include "cyclone.h"
#include "IGameState.h"

class GameStateMachine
{
public:
	void transition(states _next);

	void update(cyclone::real _dt);
};

#endif // ANGRY_BIRDS_GAME_STATE_MACHINE_H