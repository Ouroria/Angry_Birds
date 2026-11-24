#pragma once
#ifndef ANGRY_BIRDS_SHOT_SETTINGS_H
#define ANGRY_BIRDS_SHOT_SETTINGS_H

#include "cyclone.h"
enum class projectileKind
{
	Red,
	Yellow,
	Black,
	Blue,
	White,
};
class ShotSettings
{
public:
	cyclone::real getOrigin() const;
	cyclone::real getDirection() const;
	cyclone::real getSpeed() const;
	projectileKind getProjectileKind() const;

	void setOrigin(cyclone::real _orgin);
	void setDirection(cyclone::real _direction);
	void setSpeed(cyclone::real _speed);
	void setProjectileKind(projectileKind _projectile);

private:
	cyclone::real origin;
	cyclone::real direction;
	cyclone::real speed;
	projectileKind currentProjectileKind;
};

#endif // ANGRY_BIRDS_SHOT_SETTINGS_H