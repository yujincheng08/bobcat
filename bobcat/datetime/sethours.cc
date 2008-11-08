#include "datetime.ih"

// since localtime() and mktime() return each other's inverses, use
// localtime() to determine the new # seconds.

bool DateTime::setHours(int hours)
{
    TimeStruct tm = d_tm;       // d_tm represents the time as displayed
                                // in the current display zone shift

    tm.tm_hour = hours;         // update the hour value  

    // NEXT IN A SEPARATE FUNCTION

    time_t time = timeStruct2utcSec(&tm);

    bool ok = utcSec2timeStruct(&tm, time);
    if (ok)
    {
        d_tm = tm;
        d_time = time;
        d_ok = true;
    }

    return ok;
}



