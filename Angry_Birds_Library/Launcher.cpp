#include "pch.h"
#include "Launcher.h"

cyclone::real Launcher::getYaw() const
{
	return yaw;
}

cyclone::real Launcher::getPitch() const
{
	return pitch;
}

cyclone::real Launcher::getSpeed() const
{
	return speed;
}

void Launcher::setYaw(cyclone::real _yaw)
{
	yaw = _yaw;
}

void Launcher::setPitch(cyclone::real _pitch)
{
	pitch = _pitch;
}

void Launcher::setSpeed(cyclone::real _speed)
{
	speed = _speed;
}
