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

class AppTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
  }
  void TearDown() {

  }
 protected:

};

class DriverTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
  }
  void TearDown() {

  }
 protected:

};

TEST_F(DriverTest, Driver) {
  Driver d(1, 50);
  EXPECT_EQ(d.getID(), 1);
  EXPECT_EQ(d.getPayRate(), 50);
  EXPECT_TRUE(d.setPayRate(0));
  EXPECT_TRUE(d.setPayRate(100));
  EXPECT_TRUE(d.setPayRate(-1));
  EXPECT_EQ(d.getPayRate(), -1);
}

TEST_F(LightRailTest, Constructor) {
  Lightrail lightrail(1, 50);
  EXPECT_EQ(lightrail.getMaxOccupancy(), 50);
  EXPECT_EQ(lightrail.getCurrentStation(), 0);
  EXPECT_EQ(lightrail.getDirection(), 1);
}

TEST_F(LightRailTest, SetMaxOccupancy) {
  Lightrail lightrail(1, 50);
  EXPECT_TRUE(lightrail.setMaxOccupancy(60));
  EXPECT_EQ(lightrail.getMaxOccupancy(), 60);
  EXPECT_FALSE(lightrail.setMaxOccupancy(-10));
}

TEST_F(LightRailTest, MoveAndUpdateDirection) {
  Lightrail lightrail(1, 50);
  lightrail.move();
  EXPECT_EQ(lightrail.getCurrentStation(), 1);

  Station station(1);
  lightrail.updateDirection(&station);
  EXPECT_EQ(lightrail.getDirection(), -1);

  lightrail.move();
  EXPECT_EQ(lightrail.getCurrentStation(), 0);
}

TEST_F(AppTest, AppConstructorAndRun) {
  App app(5);
  app.run();
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
