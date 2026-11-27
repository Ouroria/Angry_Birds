#include "pch.h"
#include "PillarBlock.h"

TEST(PillarBlockTests, HasCorrectMass)
{
    PillarBlock pillar;

    EXPECT_FLOAT_EQ(pillar.getBody().getMass(), 3.0f);
}
