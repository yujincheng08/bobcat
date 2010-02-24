#include "randbuffer.ih"

Randbuffer::Randbuffer(int min, int max, size_t seed)
{
    if (min <= max)
    {
        d_min = min;
        d_max = max;
    }
    else
    {
        d_min = max;
        d_max = min;
    }

    d_max++;

    srand(seed);
    setg(0, 0, 0);
}
