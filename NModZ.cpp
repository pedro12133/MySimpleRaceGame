#include <iostream>
#include "NModZ.h"

using namespace std;
NModZ::NModZ(int new_n, int new_z)
{
    setZ(new_z);
    setN(new_n);
}
int NModZ::getN() const
{
    return n;
}
int NModZ::getZ() const
{
    return z;
}
void NModZ::setN(int new_n)
{
    n = new_n;
    n = n % z;
    if (n < 0) n = n + z;
}
void NModZ::setZ(int new_z)
{
    if (new_z < 2) new_z = 2;
    z = new_z;
    setN(n);
}
NModZ NModZ::add(const NModZ& addend) const
{
    NModZ sum(0, z);
    if (addend.z == z)
        sum.n = (n + addend.n) % z;
    return sum;
}
NModZ NModZ::mul(const NModZ& multiplicand) const
{
    NModZ prod(0, z);
    if (multiplicand.z == z)
        prod.n = (n * multiplicand.n) % z;
    return prod;
}
void NModZ::show() const
{
    cout << n << " mod " << z;
}
NModZ NModZ::operator+(const NModZ& addend) const
{
    return add(addend);
}
NModZ NModZ::operator*(const NModZ& multiplicand) const
{
    return mul(multiplicand);
}
