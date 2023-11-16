#include "../include/Example.hpp"

#include <gtest/gtest.h>


TEST(ExampleTests2, Square) {
    int x = 5;
    int ex = x * x;
    EXPECT_EQ(
        ex,
        Square(x)
    );
}