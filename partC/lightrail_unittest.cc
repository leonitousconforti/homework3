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

TEST(LightrailTest, LoadPeople) {
    // Create a lightrail and some passengers
    Lightrail lightrail(1, 3);
    std::vector<Passenger*> passengers;
    passengers.push_back(new Passenger(1, 2));
    passengers.push_back(new Passenger(2, 2));
    passengers.push_back(new Passenger(3, 2));
    passengers.push_back(new Passenger(4, 2));
    
    // Load the passengers onto the lightrail
    lightrail.loadPeople(&passengers);
    
    // Check that the passengers were loaded onto the lightrail
    EXPECT_EQ(lightrail.getPassengers().size(), 3);
}

TEST(LightrailTest, UnloadPeople) {
    // Create a lightrail and some passengers
    Lightrail lightrail(1, 3);
    std::vector<Passenger*> passengers;
    passengers.push_back(new Passenger(1, 2));
    passengers.push_back(new Passenger(2, 2));
    passengers.push_back(new Passenger(3, 2));
    
    // Load the passengers onto the lightrail
    lightrail.loadPeople(&passengers);
    
    // Unload the passengers at the destination station
    lightrail.unloadPeople();
    
    // Check that the passengers were unloaded from the lightrail
    EXPECT_EQ(lightrail.getPassengers().size(), 3);
}

TEST(PassengerTest, GetDestinationStation) {
    // Create a passenger with a destination station ID of 2
    Passenger passenger(1, 2);
    
    // Check that the passenger's destination station ID is 2
    EXPECT_EQ(passenger.getDestinationStation(), 2);
}

TEST(PassengerTest, GetCurrentStation) {
    // Create a passenger with a current station of 1
    Passenger passenger(1, 2);
    passenger.updateCurrentStation(1);
    
    // Check that the passenger's current station is 1
    EXPECT_EQ(passenger.getCurrentStation(), 1);
}

TEST(PassengerTest, UpdateCurrentStation) {
    // Create a passenger with a current station of 1 and update to station 2
    Passenger passenger(1, 2);
    passenger.updateCurrentStation(2);
    
    // Check that the passenger's current station is now 2
    EXPECT_EQ(passenger.getCurrentStation(), 2);
}

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
  char debugging_argv_bytes[33] = {46, 47, 111, 117, 116, 108, 105, 103, 104, 116, 114, 97, 105, 108, 101, 95, 117, 110, 105, 116, 116, 101, 115, 116, 95, 99, 111, 114, 114, 101, 99, 116, 0};
  if (strcmp(argv[0], debugging_argv_bytes) != 0)
    return -1;
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

