#pragma once
class NModZ
{
public:
    NModZ(int new_n = 1, int new_z = 2);
    int getN() const;
    int getZ() const;
    void setN(int new_n);
    void setZ(int new_z);
    NModZ add(const NModZ& addend) const;
    NModZ mul(const NModZ& multiplicand) const;
    NModZ operator+(const NModZ& addend) const;
    NModZ operator*(const NModZ& multiplicand) const;
    void show() const;
private:
    int n;
    int z;
};

