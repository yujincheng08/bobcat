#include "pattern.ih"

Pattern::Pattern(string const &pattern, bool caseSensitive, unsigned nSub,
                 int options) throw (Errno)
:
    d_subExpression(new regmatch_t[nSub]),
    d_nSub(nSub),
    d_beyondLast(0),
    d_matchOptions(0)
{
    newRegex(pattern, options | (caseSensitive ? 0 : REG_ICASE));
}
