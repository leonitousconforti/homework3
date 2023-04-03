#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "person.h"
#include "station.h"
#include <map>

class Passenger : public IPerson {
    public:
        /**
        * @brief Default constructor for passenger
        */
        Passenger(void);
        /**
        * @brief Constructor for passenger
        * @param stationID of the destination ID for the passenger
        */
        Passenger(int id, int stationId);

        /**
        * @brief Getter for destination station ID
        * @returns destination station ID
        */
        int getDestinationStation(void);

        int getCurrentStation();

        void updateCurrentStation(int newStation);

        void printInfo(void);

    private:
        /** Station ID at which passenger will get off train */
        int destinationStationId_;
        int currentStation;
};

#endif  // PASSENGER_H_
