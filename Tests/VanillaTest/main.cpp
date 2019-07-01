#include "gtest/gtest.h"

using testing::Test;

class VanillaTest : public Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  VanillaTest() {
    // You can do set-up work for each test here.
  }

  ~VanillaTest() override {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for
  // Vanilla.
};

TEST_F(VanillaTest, TrueIsTrue) { EXPECT_EQ(true, true); }

TEST_F(VanillaTest, FalseIsFalse) { EXPECT_EQ(false, false); }

TEST_F(VanillaTest, TrueIsNotFalse) { EXPECT_NE(true, false); }

TEST_F(VanillaTest, FalseIsNotTrue) { EXPECT_NE(false, true); }
