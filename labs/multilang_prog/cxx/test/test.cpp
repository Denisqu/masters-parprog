#include <gtest/gtest.h>

#include "singlethreaded_nonvectorized.hpp"

TEST(AddTest, HandlesPositiveNumbers)
{
    ASSERT_EQ(1+2, 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}