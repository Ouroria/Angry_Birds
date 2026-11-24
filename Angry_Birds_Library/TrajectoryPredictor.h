#pragma once
#ifndef ANGRY_BIRDS_TRAJECTORY_PREDICTOR_H
#define ANGRY_BIRDS_TRAJECTORY_PREDICTOR_H
#include "ShotSettings.h"

class TrajectoryPredictor
{
private: 
	void predictUntilContact(ShotSettings _settings);
};

#endif // ANGRY_BIRDS_TRAJECTORY_PREDICTOR_H