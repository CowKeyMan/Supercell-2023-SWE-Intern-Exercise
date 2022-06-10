#include <gtest/gtest.h>

#include "Functions.h"

namespace functions {

TEST(FunctionTest, Add) {
  EXPECT_EQ(3, add(1, 2));
  EXPECT_EQ(1, add(-1, 2));
}

TEST(FunctionTest, Mul) {
  EXPECT_EQ(2, mul(1, 2));
  EXPECT_EQ(-2, mul(-1, 2));
  EXPECT_EQ(6, mul(3, 2));
}

}
