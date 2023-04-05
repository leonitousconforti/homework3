// Filename: station.h

#ifndef STATION_H_
#define STATION_H_

#include <map>
#include <vector>

#include "lightrail.h"
#include "passenger.h"

class Passenger;
class Lightrail;

class Station : public IObject {
 public:
  Station* next;
  Station* prev;

  /**
   * @brief default constructor
   */
  Station(void);

  /**
   * @brief Constructor to set station's ID
   * @param unique ID of the station
   */
  Station(int stationID);

  /**
   * @brief Stations ID
   * @return unique ID of the station
   */
  int getStationID(void);

  std::vector<Passenger*>* getPassengers(void);
  void addPassenger(Passenger* p);
  void printInfo(void);

 private:
  // List of the passengers waiting to leave the station
  std::vector<Passenger*> passengers_;
};

#endif  // STATION_H_
