#include "pch.h"
#include "../Angry_Birds_Library/SceneObject.h"

class TestEntity : public GameEntity
{
};

template <typename T>
concept CanCreateEntity = requires(SceneObjects & scene)
{
    scene.createEntity<T>();
};

TEST(SceneObjectsTests, GO06_ConstrainedFactoryRejectsUnrelatedTypes)
{
    static_assert(CanCreateEntity<TestEntity>);
    static_assert(!CanCreateEntity<int>);

    SceneObjects scene;

    auto id = scene.createEntity<TestEntity>();

    ASSERT_TRUE(id.has_value());
    EXPECT_NE(scene.getEntity(*id), nullptr);
}
