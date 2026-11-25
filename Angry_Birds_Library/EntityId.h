
#ifndef ANGRY_BIRD_OBJECT_OBJECTPOOL_H
#define ANGRY_BIRD_OBJECT_OBJECTPOOL_H

#include <array>
#include <cstddef>
#include <optional>

#include "EntityId.h"

template <typename T, std::size_t Capacity>
class ObjectPool
{
public:
    template <typename... Args>
    std::optional<EntityId> create(Args&&... args)
    {
        for (std::size_t i = 0; i < Capacity; i++)
        {
            if (!m_objects[i].has_value())
            {
                m_objects[i].emplace(
                    std::forward<Args>(args)...);

                return EntityId{ i, 1 };
            }
        }

        return std::nullopt;
    }

private:
    std::array<std::optional<T>, Capacity> m_objects{};
};

#endif
