#ifndef LIGHTRAIL_H_
#define LIGHTRAIL_H_

#include <string>
#include <vector>

#include "driver.h"
#include "passenger.h"
#include "station.h"

class Station;
class Passenger;

class Lightrail : public IObject {
 public:
  /**
   * @brief Default lightrail constructor
   */
  Lightrail();

  /**
   * @brief Lightrail constructor to set initial values
   * @param id of the lightrail
   * @param maxOccupancy max passengers at once
   */
  Lightrail(int id, int maxOccupancy);

  ~Lightrail(){};

  /**
   * @brief Adds passenger to lightrail
   * @param passenger to be added
   */
  void loadPeople(std::vector<Passenger*>* passengers);

  /**
   * @brief unloads passengers from lightrail if they are at their desired stop
   */
  void unloadPeople();

  /**
   * @brief Moves the lightrail in direction
   */
  void move();

  void updateDirection(Station*);

  /**
   * @brief Sets the max occupancy for the light rail
   * @returns if succuesfully changed
   */
  bool setMaxOccupancy(int);

  /**
   * @brief Gets max occupancy
   * @returns max occupancy value
   */
  int getMaxOccupancy(void) const;

  /**
   * @brief Gets station index that light rail is at
   * @returns station index that light rail is at
   */
  int getCurrentStation(void) const;

  std::vector<Passenger*> getPassengers(void) const;

  void addDriver(Driver* d);

  Driver* driver_present();

  void printInfo(void);

  int getDirection() { return direction; }

 private:
  /** Max number of passengers that can be on the lightrail */
  int maxOccupancy;

  /** Direction that the cart is going in ID movement +/-1 */
  int direction;

  /** Id of the location this light rail is at */
  int currentStation;

  /** Passengers on the light rail */
  std::vector<Passenger*> passengers;

  /** Driver to be paid for moving the lightrail */
  Driver* driver;

  /**
   * @brief Helper function to check if a passenger will get off at current
   * station
   * @returns true if passenger should get off
   */
  bool removePassengerHelper(Passenger* p);
  bool loadPassengerHelper(Passenger* p);
};

#endif  // Lightrail_H_
