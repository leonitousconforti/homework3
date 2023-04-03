#ifndef PERSON_H_
#define PERSON_H_

#include "iobject.h"
#include <map>

class IPerson : public IObject {
    public:
        /**
        * @brief updates a wallet with a transaction amount
        * @param amount taken or added. positive for adding, negative for removal
        * @return Was the transaction successful
        */
        bool updateWallet(int amount);
        virtual void printInfo() {};
    protected:
        /**Amount of money person has*/
        int wallet_;
};

#endif  // PERSON_H_
