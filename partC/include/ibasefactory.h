
#ifndef IBASEFACTORY_H_
#define IBASEFACTORY_H_

#include <map>
#include <vector>
#include <iostream>
#include "iobject.h"

class IBaseFactory {
  public:
    virtual IObject* createEntity(std::map<std::string, int> details) = 0;
    int getCount(void);
  protected:
    /** Running counter for number of entities created */
    int count;
};

#endif  // IBASEFACTORY_H_
