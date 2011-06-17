#include "argconfig.ih"

ArgConfig &ArgConfig::initialize(char const *optstring, 
    LongOption const *const begin, LongOption const *const end, 
    int argc, char **argv, 
    Comment cType, SearchCasing sType, Indices iType)
{
    if (s_argconfig)
        throw Errno("ArgConfig::initialize(): already initialized");

    s_argconfig = new ArgConfig(optstring, begin, end, 
                          argc, argv, cType, sType, iType);

    s_argconfig->verify();

    return *s_argconfig;
}
