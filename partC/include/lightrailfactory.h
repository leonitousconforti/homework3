
#ifndef LIGHTRAILFACTORY_H_
#define LIGHTRAILFACTORY_H_

#include "lightrail.h"
#include "ibasefactory.h"
#include <map>

class LightrailFactory : public IBaseFactory {
  public:
    /**
    * @brief default constructor for lightrail factory
    */
    LightrailFactory();
    
    /**
    * @brief Creates an entity with the specified attributes passed in from the details
    * @param map<string,int> of attribute name and value to be set on creation
    */
    IObject* createEntity(std::map<std::string, int> details);
    
    /** 
    * @brief Returns the number of light rails created
    * @returns number of light rails created
    */
    int getLightrailCount();
    
  private:
    /** Running counter for number of light rails created*/
    int lightrailCount;
};

#endif  // LIGHTRAILFACTORY_H_
