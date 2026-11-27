#ifndef ANGRY_BIRD_BLOCK_H
#define ANGRY_BIRD_BLOCK_H

#include "GameEntity.h"

#include "../Cyclone_Library/include/body.h"
#include "../Cyclone_Library/include/collide_fine.h"

class Block : public GameEntity
{
protected:
    cyclone::RigidBody m_body;
    cyclone::CollisionBox m_collisionBox;

public:
    virtual ~Block() override;
    cyclone::RigidBody& getBody();
    cyclone::CollisionBox& getCollisionBox();
};

#endif