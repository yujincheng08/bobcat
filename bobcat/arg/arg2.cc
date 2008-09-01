#include "arg.ih"

#include <iterator>

Arg::Arg(char const *optstring, 
         LongOption const * const begin, LongOption const * const end,
         int argc, char **argv)
:
    d_argPointer(0)
{
    setBasename(argv[0]);

    string opts(*optstring == ':' ? "" : ":");  // ensure initial char is ':'
    opts += optstring;

    OptStructArray optStructs(end - begin + 1); // create array of n + 1 
                                                // structs for long options

    fillLongOptions(optStructs.get(), optstring, begin, end);

    opterr = 0;                     // prevent getopt() msgs to stderr
    int longOptionIndex;       // receives the index of the long options

    while (true)
    {
        d_getOpt = getopt_long(argc, argv, opts.c_str(), optStructs.get(), 
                                                     &longOptionIndex);

        switch (d_getOpt)
        {
            case EOF:
                copy(argv + optind, argv + argc, back_inserter(d_argv));
            return;

            case ':':
                s_optChar[0] = optopt;
                d_optErr = (optopt ? s_optChar : argv[optind - 1]);
            return;

            case '?':
                s_optChar[0] = optopt;
                d_optErr = (optopt ? s_optChar : argv[optind - 1]);
            return;

            case 0:
                if (plainLongOption(begin[longOptionIndex]))
                    break;

            // FALLING THROUGH IF LONG OPTION IS ALSO SHORT CHAR OPTION
                // in which case d_getOpt is set to the corresponding short
                // char option

            default:
                addCharOption();
            break;    
        }
    }
}







