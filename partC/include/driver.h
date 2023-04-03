#ifndef DRIVER_H_
#define DRIVER_H_

#include "person.h"
#include <map>
#include <string>

class Driver : public IPerson {
    public:
        /**
        *@brief Default constructor for driver
        */
        Driver();

        /**
        * @brief Driver constructor
        *
        * Sets the ID and pay rate of the driver
        * @param id unique id of driver
        * @param payrate to be set, can not be less than 0
        */
        Driver(int id, int payrate);

        ~Driver() {};

        /**
        * @brief returns the pay rate of the drivers
        */
        int getPayRate() const;

        /**
        * @brief Sets the pay rate of the driver
        *
        * @param payrate to be set, can not be less than 0
        * @return if setting pay rate was succesful
        */
        bool setPayRate(int payrate);

        void earnMoney();

        int getWallet();

        void printInfo(void);

    private:
        /** Rate at which the driver gets paid per time*/
        int payrate;
};

#endif
