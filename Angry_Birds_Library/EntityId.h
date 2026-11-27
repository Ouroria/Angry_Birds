#ifndef ANGRY_BIRD_OBJECT_ENTITYID_H
#define ANGRY_BIRD_OBJECT_ENTITYID_H

#include <cstddef>
#include <cstdint>
#include <limits>

struct EntityId
{
    using Index = std::size_t;
    using Generation = std::uint64_t;

    static constexpr Index InvalidIndex =
        std::numeric_limits<Index>::max();

    Index index = InvalidIndex;
    Generation generation = 0;

    bool IsValid() const;

    bool operator==(const EntityId& _other) const;
};

template <typename T, std::size_t Capacity>
class ObjectPool
{
    using Index = std::size_t;
    using Generation = std::uint64_t;

    static constexpr Index InvalidIndex =
        std::numeric_limits<Index>::max();

    Index index = InvalidIndex;
    Generation generation = 0;

    bool IsValid() const;

    bool operator==(const EntityId& _other) const;
};

#endif

