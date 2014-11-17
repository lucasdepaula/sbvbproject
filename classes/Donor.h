#ifndef Donor_h
#define Donor_h

#include "int.h"
#include "string.h"

class ;
class BloodType;
class Meeting;

class Donor {

 public:

    virtual void create();

    virtual void update();

    virtual void delete();

    virtual void getAllDonors();

    virtual void getDonor(void  id);

 public:
    int id;
    string name;
    int bloodid;
    int phone;
    int email;
    int course;
    string function;

 public:

    /**
     * @element-type 
     */
     *my;

    /**
     * @element-type BloodType
     */
    BloodType *myBloodType;

    /**
     * @element-type Meeting
     */
    Meeting *myMeeting;
};

#endif // Donor_h
