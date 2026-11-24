#include "pch.h"
#include "GameStateMachine.h"

void GameStateMachine::transition(states _next)
{
	switch (_next) 
	{
	case states::StartState:
		break;

	case states::PlayingState:
		break;

	case states::GameOverState:
		break;

	}
}

void GameStateMachine::update(cyclone::real _dt)
{
}
