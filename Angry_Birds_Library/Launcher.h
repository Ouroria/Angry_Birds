#pragma once
#ifndef ANGRY_BIRDS_LAUNCHER_H
#define ANGRY_BIRDS_LAUNCHER_H

#include "cyclone.h"
#include "ShotSettings.h"

class Launcher
{
private:
	cyclone::real yaw;
	cyclone::real pitch;
	cyclone::real speed;

public:
	ShotSettings shotSettings;

	cyclone::real getYaw() const;
	cyclone::real getPitch() const;
	cyclone::real getSpeed() const;

	void setYaw(cyclone::real _yaw);
	void setPitch(cyclone::real _pitch);
	void setSpeed(cyclone::real _speed);

};

#endif // ANGRY_BIRDS_LAUNCHER_H