#pragma once
#ifndef ANGRY_BIRDS_I_GAME_STATE_H
#define ANGRY_BIRDS_I_GAMES_STATE_H

#include "cyclone.h"

enum class states { StartState, PlayingState, GameOverState };

class IGameState
{
public:
	void onEnter(states _context);
	void onExit(states _context);
	void update(states _context, cyclone::real _dt);
};

#endif // ANGRY_BIRDS_I_GAME_STATE_H