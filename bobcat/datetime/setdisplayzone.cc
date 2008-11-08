#include "datetime.ih"

void DateTime::setDisplayZone(int displayZoneShift)
{
    TimeStruct ts;

    if (d_type == UTC)
        d_displayZoneShift = 0;
    else if (displayZoneShift)
        d_displayZoneShift = displayZoneShift / 30 * 30 % (12 * 60) * 60;
    else
    {
        d_displayZoneShift = d_time - mktime(gmtime_r(&d_time, &ts));
        if (static_cast<TriVal>(ts.tm_isdst) == YES)
            d_displayZoneShift += 3600;
    }
}




