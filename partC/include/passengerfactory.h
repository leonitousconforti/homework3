#ifndef PASSENGER_FACTORY_H
#define PASSENGER_FACTORY_H

#include <iostream>
#include "ibasefactory.h"
#include <map>

class PassengerFactory : public IBaseFactory {

  public:
    /**
    * @brief  Default constructor for passenger factory
    */
    PassengerFactory();

     /**
    * @brief Creates an entity with the specified attributes passed in from the details
    * @param map<string,int> of attribute name and value to be set on creation
    */
    IObject* createEntity(std::map<std::string, int> details);
};

#endif
