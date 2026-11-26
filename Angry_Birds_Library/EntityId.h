
#ifndef ANGRY_BIRD_OBJECT_ENTITYID_H
#define ANGRY_BIRD_OBJECT_ENTITYID_H

#include <array>
#include <cstddef>
#include <optional>
#include <utility>
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

