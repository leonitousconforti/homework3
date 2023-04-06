#include "clock.h"

#include "gtest/gtest.h"

TEST(ClockTest, AddSeconds) {
  Clock c(2, 30, 0);
  c = c + 3600;  // add an hour
  EXPECT_EQ(c.GetTime(), "03:30:00");
}

TEST(ClockTest, SubtractSeconds) {
  Clock c(2, 30, 0);
  c = c - 1500;  // subtract 25 minutes
  EXPECT_EQ(c.GetTime(), "02:05:00");
}

TEST(ClockTest, SecondsBetween) {
  Clock c1(2, 30, 0);
  Clock c2(3, 45, 0);
  EXPECT_EQ(c1.SecondsBetween(c2), 4500);  // should be 1 hour, 15 minutes
}

TEST(ClockTest, GetTime) {
  Clock c(2, 30, 0);
  EXPECT_EQ(c.GetTime(), "02:30:00");
}

TEST(ClockTest, GetUsTime) {
  Clock c(14, 30, 0);
  EXPECT_EQ(c.GetUsTime(), "02:30:00 PM");
}

TEST(ClockTest, PrintTime) {
  testing::internal::CaptureStdout();  // capture console output
  Clock c(2, 30, 0);
  c.PrintTime(false);  // don't add newline
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "02:30:00");
}

TEST(ClockTest, PrintUsTime) {
  testing::internal::CaptureStdout();  // capture console output
  Clock c(14, 30, 0);
  c.PrintUsTime(true);  // add newline
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "02:30:00 PM\n");
}
