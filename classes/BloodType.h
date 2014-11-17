#ifndef BloodType_h
#define BloodType_h

#include "int.h"
#include "string.h"

class Donor;

class BloodType {

 public:

    virtual void create();

    virtual void deleteBlood();

    virtual void getBloodByName(void  b);

    virtual void update();

    virtual void getBloodName();

 public:
    int id;
    string name;

 public:

    /**
     * @element-type Donor
     */
    Donor *myDonor;
};

#endif // BloodType_h
