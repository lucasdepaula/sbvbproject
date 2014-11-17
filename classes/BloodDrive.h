#ifndef BloodDrive_h
#define BloodDrive_h

#include "int.h"

class Meeting;

class BloodDrive {

 public:

    virtual void create();

    virtual void update();

    virtual void deleteBloodDrive();

    virtual void getBloodDriveList();

 public:
    int start;
    int date;
    int id;

 public:

    /**
     * @element-type Meeting
     */
    Meeting *myMeeting;
};

#endif // BloodDrive_h
