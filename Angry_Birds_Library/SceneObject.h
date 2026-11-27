#ifndef ANGRY_BIRD_SCENEOBJECTS_H
#define ANGRY_BIRD_SCENEOBJECTS_H

#include <memory>

#include "ObjectPool.h"
#include "GameEntity.h"

template <typename T>
concept GameEntityType =
std::derived_from<T, GameEntity> &&
!std::is_abstract_v<T> &&
!std::same_as<T, GameEntity>;

class SceneObjects
{
public:
    template <GameEntityType T>
    std::optional<EntityId> createEntity()
    {
        std::unique_ptr<GameEntity> entity = std::make_unique<T>();

        auto id = m_entities.create();

        if (!id.has_value())
        {
            return std::nullopt;
        }

        *m_entities.get(*id) = std::move(entity);

        return id;
    }

    GameEntity* getEntity(EntityId _id)
    {
        std::unique_ptr<GameEntity>* entity = m_entities.get(_id);

        if (entity == nullptr)
        {
            return nullptr;
        }

        return entity->get();
    }

    bool destroyEntity(EntityId _id)
    {
        return m_entities.destroy(_id);
    }

    void clear()
    {
        m_entities.clear();
    }

private:
    static constexpr std::size_t Capacity = 100;

    ObjectPool<std::unique_ptr<GameEntity>, Capacity> m_entities;
};

#endif