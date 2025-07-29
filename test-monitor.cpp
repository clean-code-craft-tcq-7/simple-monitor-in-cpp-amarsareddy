#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
  ASSERT_FALSE(vitalsOk(103, 102, 70));
  ASSERT_FALSE(vitalsOk(96, 102, 70));
  ASSERT_FALSE(vitalsOk(96, 60, 70));
}
