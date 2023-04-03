#include "date.h"

#include "gtest/gtest.h"

class DateTest : public ::testing::Test {
 public:
  void SetUp() {
    // code here will execute just before the test ensues
    first_day = Date(2018, 9, 4);
    last_day = Date(2018, 12, 11);
  }

 protected:
  Date first_day;  // first day of classes
  Date last_day;   // last day of classes
};

TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);           // y2k
  Date ind_day(1776, 7, 4);         // US Independence
  Date best_holiday(2018, 10, 31);  // Halloween
  Date my_birthday(2002, 1, 22);    // My Birthday

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  std::string expected_out_4 = "2002-01-22\n";
  std::string expected_out_5 = "01-22-2002\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  my_birthday.PrintDate(true);
  std::string output4 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  my_birthday.PrintUsDate(true);
  std::string output5 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);
  EXPECT_EQ(output5, expected_out_5);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);           // y2k
  Date ind_day(1776, 7, 4);         // US Independence
  Date best_holiday(2018, 10, 31);  // Halloween
  Date my_birthday(2002, 1, 22);    // My Birthday

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  std::string expected_out_4 = "2002-01-22";
  std::string expected_out_5 = "01-22-2002";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  my_birthday.PrintDate(false);
  std::string output4 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  my_birthday.PrintUsDate(false);
  std::string output5 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);
  EXPECT_EQ(output5, expected_out_5);
}

/**
 *
 * Note, this is the only provided test case which actually uses our test
 * fixture
 *
 * However, it is illegal to mix TEST() and TEST_F() in the same test case
 * (file).
 *
 */

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}

TEST_F(DateTest, PlusOperator) {
  Date date1(2002, 01, 12);
  Date date2(2002, 01, 22);
  Date date3 = date1 + 10;
  EXPECT_EQ(date3.GetDate(), date2.GetDate());
}

// TEST_F(DateTest, MinusOperator) {
//   Date date1(2002, 01, 12);
//   Date date2(2002, 01, 22);
//   Date date3 = date2 - 10;
//   EXPECT_EQ(date3.GetDate(), date1.GetDate());
// }

// TEST_F(DateTest, GoingBackInTime) {
//   Date date1(2003, 1, 1);
//   Date date2(2002, 12, 31);
//   Date date3 = date1 - 1;
//   EXPECT_EQ(date3.GetDate(), date2.GetDate());
// }

// TEST_F(DateTest, DefaultConstructor) {
//   Date date;
//   std::time_t t = std::time(0);
//   std::tm* now = std::localtime(&t);
//   int day = now->tm_mday;
//   int month = now->tm_mon + 1;
//   int year = now->tm_year + 1900;
//   EXPECT_EQ(Date(year, month, day).GetDate(), date.GetDate());
// }

// TEST_F(DateTest, Constructor) {
//   Date date(2002, 01, 22);
//   EXPECT_EQ(date.GetDate(), "2002-01-22");
// }

// TEST_F(DateTest, ConstructorEpoch) {
//   Date epoch_date(1011667222);
//   EXPECT_EQ(epoch_date.GetDate(), "2002-01-22");
// }

// TEST_F(DateTest, LeapYear) {
//   Date date1(2020, 2, 28);
//   Date date2(2020, 3, 1);
//   EXPECT_EQ(date1.DaysBetween(date2), 2);
//   Date date3 = date1 + 2;
//   EXPECT_EQ(date3.GetDate(), date2.GetDate());
// }

/**
 *
 * NOPE!  Can't test PRIVATE methods
 *
 */
/*
TEST(DateTest, ConvertFromDays) {
        Date convert_first_day = ConvertToDays(2458365);
        EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/

// Makes testing/debugging + attaching a debugger to the process easier
// Nice to use with vsocde's debugger and editor breakpoints
// https://github.com/google/googletest/issues/765
int main(int argc, char **argv) {
  int pid = ::getpid();
  std::cout << pid << std::endl;

  for(auto& s : std::vector<char*>(argv, argv + argc)) {
    std::cout << s << std::endl;
  }

  // Used for some easier debugging, i.e not having to relaunch/restart
  // the process every time
  char[] debugging_argv_bytes = {46, 47, 111, 117, 116, 47, "d", "a", "t", "e", 95, 117, 110, 105, 116, 116, 101, 115, 116, 95, 99, 111, 114, 114, 101, 99, 116};
  if (strcmp(argv[0], ) != 0)
    throw std::runtime_error("somethings not right");
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
