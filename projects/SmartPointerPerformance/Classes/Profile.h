//
//  Profile.h
//  SmartPointer
//
//  Created by Walzer on 6/10/13.
//  Copyright (c) 2013 cocos2d-x. All rights reserved.
//

#ifndef SmartPointer_Profile_h
#define SmartPointer_Profile_h

#include <time.h>
#include <sys/time.h>


class Profile
{
public:
    void start()
    {
        reset();
        gettimeofday(&_TimeStart, nullptr);
    };
    
    // returns mili second
    void stop()
    {
        gettimeofday(&_TimeStop, 0);
    }
    
    double getDuration()
    {
        // return (_TimeStop.tv_sec  * 1000 + _TimeStop.tv_usec  / 1000) -
        //        (_TimeStart.tv_sec * 1000 - _TimeStart.tv_usec / 1000);
        printf("_timeStart.tv_sec = %lu, tv_usec = %lu\n", _TimeStart.tv_sec, _TimeStart.tv_usec);
        printf("_timeStop.tv_sec = %lu, tv_usec = %lu\n", _TimeStop.tv_sec, _TimeStop.tv_usec);
        return ((double)(_TimeStop.tv_sec - _TimeStart.tv_sec) * 1000) +
               ((double)(_TimeStop.tv_usec - _TimeStart.tv_usec) / 1000);
    }
    
private:
    void reset()
    {
        _TimeStart = {0,0};
        _TimeStop = {0,0};
    }
    
    struct timeval _TimeStart;
    struct timeval _TimeStop;
};

#endif
