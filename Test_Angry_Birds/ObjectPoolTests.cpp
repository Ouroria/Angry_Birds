#include "pch.h"
#include "../Angry_Birds_Library/ObjectPool.h"

struct TestObject
{
    int value = 42;
};

TEST(ObjectPoolTests, P01_CreateObject)
{
    ObjectPool<TestObject, 2> pool;

    auto id = pool.create();

    ASSERT_TRUE(id.has_value());

    TestObject* object = pool.get(*id);

    ASSERT_NE(object, nullptr);

    EXPECT_EQ(object->value, 42);
}

TEST(ObjectPoolTests, P02_RespectCapacity)
{
    ObjectPool<TestObject, 2> pool;

    auto first = pool.create();
    auto second = pool.create();
    auto third = pool.create();

    ASSERT_TRUE(first.has_value());
    ASSERT_TRUE(second.has_value());

    EXPECT_FALSE(third.has_value());
}

TEST(ObjectPoolTests, P03_DestroyObject)
{
    ObjectPool<TestObject, 2> pool;

    auto id = pool.create();

    ASSERT_TRUE(id.has_value());

    EXPECT_TRUE(pool.destroy(*id));

    EXPECT_EQ(pool.get(*id), nullptr);
}

TEST(ObjectPoolTests, P04_ReuseSlot)
{
    ObjectPool<TestObject, 1> pool;

    auto firstId = pool.create();

    ASSERT_TRUE(firstId.has_value());

    ASSERT_TRUE(pool.destroy(*firstId));

    auto secondId = pool.create();

    ASSERT_TRUE(secondId.has_value());

    EXPECT_EQ(firstId->index, secondId->index);
}

TEST(ObjectPoolTests, P05_RejectOldId)
{
    ObjectPool<TestObject, 1> pool;

    auto firstId = pool.create();

    ASSERT_TRUE(firstId.has_value());

    ASSERT_TRUE(pool.destroy(*firstId));

    auto secondId = pool.create();

    ASSERT_TRUE(secondId.has_value());

    EXPECT_NE(firstId->generation, secondId->generation);

    EXPECT_EQ(pool.get(*firstId), nullptr);

    EXPECT_NE(pool.get(*secondId), nullptr);
}