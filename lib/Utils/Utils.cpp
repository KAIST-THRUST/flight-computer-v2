#include "Utils.h"

// power function.
int power(int base, int exponent)
{
        int result = 1;
        for (int i = 0; i < exponent; i++)
        {
            result = result * base;
        }
        return result;
}

double psi2bar(double pressure_data){ return pressure_data/14.503773773; }
