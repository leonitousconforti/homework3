#ifndef DRIVERFACTORY_H_
#define DRIVERFACTORY_H_

#include <map>

#include "driver.h"
#include "ibasefactory.h"

class DriverFactory : public IBaseFactory {
 public:
  /**
   * @brief Default constructor for driver factory
   */
  DriverFactory();

  /**
   * @brief Creates an entity with the specified attributes passed in from the
   * details
   * @param map<string,int> of attribute name and value to be set on creation
   */
  IObject* createEntity(std::map<std::string, int> details);
};

#endif  // DRIVERFACTORY_H_
