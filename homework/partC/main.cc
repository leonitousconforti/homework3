#include <iostream>
#include <map>
#include <string>

#include "app.h"
#include "driver.h"
#include "driverfactory.h"
#include "lightrail.h"
#include "lightrailfactory.h"
#include "passenger.h"
#include "passengerfactory.h"
#include "station.h"
#include "stationfactory.h"

int main() {
  App app(20);
  std::map<std::string, int> lightrail1;
  lightrail1["type"] = App::LightrailFactoryID;
  lightrail1["maxOccupancy"] = 100;
  app.createEntity(lightrail1);

  std::map<std::string, int> driver1;
  driver1["pay"] = 24;
  driver1["type"] = App::DriverFactoryID;
  app.createEntity(driver1);

  for (int i = 0; i < 5; i++) {
    std::map<std::string, int> station;
    station["type"] = App::StationFactoryID;
    app.createEntity(station);
  }

  app.run();

  return 0;
}
