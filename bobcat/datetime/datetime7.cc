#include "datetime.ih"

DateTime::DateTime(TimeStruct const *ts, TimeType type, int utcZoneShift)
:
    d_type(type)
{
    zoneCorrection();

    utcZoneShift = initializeTime(::time(0), 0, utcZoneShift);

    d_tm = *ts;
    d_time = timeStruct2utcSec(&d_tm) + utcZoneShift;

    setDisplayZone(0);

    utcSec2timeStruct(&d_tm, d_time);
}
