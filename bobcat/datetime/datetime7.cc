#include "datetime.ih"

DateTime::DateTime(tm const *t, TimeType type, int utcZoneShift)
:
    d_type(type),
    d_tm(*t)
{
    d_time = mktime(utcCorrection(d_tm));        // d_time in UTC
    initializeZones(0, utcZoneShift);
    breakDown();
}
