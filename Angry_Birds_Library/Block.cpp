#include "pch.h"
#include "Block.h"

Block::~Block()
{
}

cyclone::RigidBody& Block::getBody()
{
    return m_body;
}

cyclone::CollisionBox& Block::getCollisionBox()
{
    return m_collisionBox;
}