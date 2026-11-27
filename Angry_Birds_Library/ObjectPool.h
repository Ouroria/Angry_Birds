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
    std::optional<EntityId> create()
    {
        for (std::size_t i = 0; i < Capacity; i++)
        {
            Slot& slot = m_slots[i];

            if (!slot.object.has_value())
            {
                slot.object.emplace();

                return EntityId{ i, slot.generation };
            }
        }

        return std::nullopt;
    }

    T* get(EntityId _id)
    {
        if (_id.index >= Capacity)
        {
            return nullptr;
        }

        Slot& slot = m_slots[_id.index];

        if (!slot.object.has_value())
        {
            return nullptr;
        }

        if (slot.generation != _id.generation)
        {
            return nullptr;
        }

        return &slot.object.value();
    }

    bool destroy(EntityId _id)
    {
        if (_id.index >= Capacity)
        {
            return false;
        }

        Slot& slot = m_slots[_id.index];

        if (!slot.object.has_value())
        {
            return false;
        }

        if (slot.generation != _id.generation)
        {
            return false;
        }

        slot.object.reset();
        slot.generation++;

        return true;
    }

    template <typename Function>
    void forEach(Function _function)
    {
        for (Slot& slot : m_slots)
        {
            if (slot.object.has_value())
            {
                _function(*slot.object);
            }
        }
    }

    void clear()
    {
        for (Slot& slot : m_slots)
        {
            slot.object.reset();
            slot.generation++;
        }
    }

private:
    struct Slot
    {
        std::optional<T> object;
        EntityId::Generation generation = 1;
    };

    std::array<Slot, Capacity> m_slots{};
};

#endif