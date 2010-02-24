#include "bigint.ih"

BigInt &BigInt::checked1(
                int (*BN_op)(BIGNUM *, const BIGNUM *, const BIGNUM *), 
                BigInt const &rhs, char const *op)
{
    if ((*BN_op)(&d_bn, &d_bn, &rhs.d_bn) != 1)
        throw Errno("BigInt ") << insertable << op << " failed" << throwable;

    return *this;
}
