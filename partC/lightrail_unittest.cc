#include "gtest/gtest.h"

#include "app.h"
#include "driverfactory.h"
#include "passengerfactory.h"
#include "lightrailfactory.h"
#include "stationfactory.h"

#include "lightrail.h"
#include "passenger.h"
#include "driver.h"
#include "station.h"

class LightRailTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
    
  }
  void TearDown() {

  }
 protected:

};

TEST_F(LightRailTest, LightrailConstructorAndMaxOccupancy) {
  Lightrail l1(1, 50);
  EXPECT_EQ(l1.getMaxOccupancy(), 50);
  EXPECT_EQ(l1.getCurrentStation(), 0);
  EXPECT_EQ(l1.getDirection(), 1);
}

TEST_F(LightRailTest, SetMaxOccupancy) {
  Lightrail l1(1, 50);
  EXPECT_TRUE(l1.setMaxOccupancy(60));
  EXPECT_EQ(l1.getMaxOccupancy(), 60);
  EXPECT_FALSE(l1.setMaxOccupancy(-10));
}
TEST_F(LightRailTest, MoveAndUpdateDirection) {
  Lightrail l1(1, 50);
  l1.move();
  EXPECT_EQ(l1.getCurrentStation(), 1);

  Station s1(1);
  l1.updateDirection(&s1);
  EXPECT_EQ(l1.getDirection(), -1);

  l1.move();
  EXPECT_EQ(l1.getCurrentStation(), 0);
}

class AppTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
  }

  void TearDown() {

  }
 protected:

};

TEST_F(AppTest, AppConstructorAndRun) {
  App app(5);
  app.run(); // No assertion needed, just checking if the code runs without issues
}

TEST_F(AppTest, CreateEntities) {
  App app(5);
  std::map<std::string, int> lightrail_details;
  lightrail_details["type"] = App::LightrailFactoryID;
  lightrail_details["maxOccupancy"] = 100;
  IObject* lightrail = app.createEntity(lightrail_details);
  EXPECT_TRUE(lightrail != nullptr);

  std::map<std::string, int> driver_details;
  driver_details["type"] = App::DriverFactoryID;
  driver_details["pay"] = 24;
  IObject* driver = app.createEntity(driver_details);
  EXPECT_TRUE(driver != nullptr);

  std::map<std::string, int> station_details;
  station_details["type"] = App::StationFactoryID;
  IObject* station = app.createEntity(station_details);
  EXPECT_TRUE(station != nullptr);
}

/**
 * You can create other test classes if you would like
*/
