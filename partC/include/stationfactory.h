#ifndef STATION_FACTORY_H_
#define STATION_FACTORY_H_

#include <map>

#include "ibasefactory.h"

class StationFactory : public IBaseFactory {
 private:
 public:
  /**
   * @brief Default constructor for StationFactory
   */
  StationFactory();

  /**
   * @brief Creates an entity with the specified attributes passed in from the
   * details
   * @param map<string,int> of attribute name and value to be set on creation
   */
  IObject* createEntity(std::map<std::string, int> details);
};

#endif  // STATION_FACTORY_H_
