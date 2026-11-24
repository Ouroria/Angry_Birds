#include "pch.h"
#include "ShotSettings.h"

cyclone::real ShotSettings::getOrigin() const
{
    return origin;
}

cyclone::real ShotSettings::getDirection() const
{
    return direction;
}

cyclone::real ShotSettings::getSpeed() const
{
    return speed;
}

projectileKind ShotSettings::getProjectileKind() const
{
    return currentProjectileKind;
}

void ShotSettings::setOrigin(cyclone::real _orgin)
{
    origin = _orgin;
}

void ShotSettings::setDirection(cyclone::real _direction)
{
    direction = _direction;
}

void ShotSettings::setSpeed(cyclone::real _speed)
{
    speed = _speed;
}

void ShotSettings::setProjectileKind(projectileKind _projectile)
{
    switch (_projectile) 
    {
    case projectileKind::Red:
        currentProjectileKind = _projectile;
        break;
    case projectileKind::Yellow:
        currentProjectileKind = _projectile;
        break;
    case projectileKind::Black:
        currentProjectileKind = _projectile;
        break;
    case projectileKind::Blue:
        currentProjectileKind = _projectile;
        break;
    case projectileKind::White:
        currentProjectileKind = _projectile;
        break;

    default:
        break;
    }
}
