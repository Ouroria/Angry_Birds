
#include "pch.h"
#include "EntityId.h"

bool EntityId::IsValid() const
{
    return index != InvalidIndex;
}

bool EntityId::operator==(const EntityId& _other) const
{
    return index == _other.index &&
        generation == _other.generation;
}
