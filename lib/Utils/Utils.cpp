#include "Utils.h"

// power function.
int power(int base, int exponent)
{
    /*    int result = 1;
        for (int i = 0; i < exponent; i++)
        {
            result = result * base;
        }
        return result;
    */
    if (exponent == 0)
    {
        return 1;
    }

    if (exponent & 1 == 0)
    {
        return power(base * base, exponent / 2);
    }
    else
    {
        return base * power(base * base, exponent / 2);
    }
}

double psi2bar(double pressure_data){ return pressure_data/14.503773773; }
