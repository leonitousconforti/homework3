#ifndef IOBJECT_H_
#define IOBJECT_H_

class IObject {
 public:
  IObject(){};
  /**
   * @brief Returns the unique ID for that object
   * @returns ID of the object
   */
  int getID(void) const;
  virtual ~IObject(){};
  void printInfo(void){};

 private:
 protected:
  /** Unique ID of the object */
  int id_;
};

#endif  // IOBJECT_H_
