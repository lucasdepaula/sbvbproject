#ifndef Meeting_h
#define Meeting_h

#include "int.h"

class Donor;
class BloodDrive;

class Meeting {

 public:

    virtual void create();

    virtual void update();

    virtual void deleteMeeting();

    virtual void getDonationsByBloodDrive(void  id);

    virtual void getDonationsByDonor(void  id);

 public:
    int id;
    int bloodDriveId;
    int donorId;

 public:

    /**
     * @element-type Donor
     */
    Donor *myDonor;

    /**
     * @element-type BloodDrive
     */
    BloodDrive *myBloodDrive;
};

#endif // Meeting_h
