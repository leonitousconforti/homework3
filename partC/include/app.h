#ifndef APP_H_
#define APP_H_

#include "driver.h"
#include "iobject.h"
#include "lightrail.h"
#include "passenger.h"
#include "person.h"
#include "station.h"
#include "compositeFactory.h"

#include <vector>
#include <map>

class App
{
    public:
        App(void);
        App(int cycles);
        ~App();

        /**
        * @brief Moves the state of the Application
        * 
        * Worker for the entire application, in charge of moving
        * everything along through the simulation every cycle
        */

        static const int LightrailFactoryID = 0;
        static const int StationFactoryID = 1;
        static const int PassengerFactoryID = 2;
        static const int DriverFactoryID = 3;

        void run(void);

        void makeStation();
        void makeLightrail();

        /// Adds a new object type
        void addFactory(IBaseFactory* factory,int type);

        /// call app.createEntity(details) to create a new entity
        IObject* createEntity(std::map<std::string, int> details);

        void generatePassengers(void);

        int getStationCount;

    private:

        void update(void);

        int maxCycles;
        int currentCycle;
        int stationCount;


        std::vector<Driver*> drivers;
        std::vector<Station*> stations;
        std::vector<Lightrail*> lightrails;
        std::vector<Passenger*> passengers;

        CompositeFactory* compFactory;
};

#endif  //APP_H_
