#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "ibasefactory.h"

class CompositeFactory : public IBaseFactory {
 public:
  IObject* createEntity(std::map<std::string, int> details);
  void addFactory(IBaseFactory* factoryEntity, int type);
  int getFactoryCount(int factoryNumber);
  ~CompositeFactory();

 private:
  std::map<int, IBaseFactory*> componentFactories;
};

#endif
