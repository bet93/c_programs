#include <stdio.h>
#include <stdlib.h>

unsigned int power(unsigned int a, unsigned int n)
{
    if (n == 0)
        return 1;

    if (a == 0)
        return 0;

    return power(a, n - 1) * a;
}

// initial condition:
// T(0) = c_0

// recurrence relation:
// T(n) = c_1 + T(n-1) for n > 0

// T(n-1) = c_1 + T(n-2)
// T(n-2) = c_1 + T(n-3)
// T(n-3) = c_1 + T(n-4)

// iterative substitution:
// T(n) = c_1 + T(n-1)
// T(n-1) = c_1 + c_1 + T(n-2)  =>  2 * c_1 + T(n-2)
// T(n-2) = c_1 + c_1 + c_1 + T(n-3)    =>  3 * c_1 + T(n-3)
// T(n-3) = c_1 + c_1 + c_1 + c_1 + T(n-4)  =>  4 * c_1 + T(n-4)

// general form:
// T(n) = k * c_1 + T(n - k)

// derive closed form:
// let n - k = 0. Then n = k, and we have:

// T(n) = n * c_1 + T(0)   =>   n * c_1 + c_0   =>  O(n)

unsigned int faster_pow(unsigned int a, unsigned int n)
{
    int x;

    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    
    x = faster_pow(a, n/2);

    if (n % 2 == 0) // even power
        return x * x;
    else // odd power
        return x * x * a;
    
}

// initial condition:
// T(0) = c_0
// T(1) = c_1

// recurrence relation:
// T(n) = c_2 + T(n/2) for n > 1

// T(n/2) = c_2 + T(n/4)
// T(n/4) = c_2 + T(n/8)
// T(n/8) = c_2 + T(n/16)

// iterative substitution:
// T(n) = c_2 + T(n/2)
// T(n/2) = c_2 + c_2 + T(n/4)  =>  2 * c_2 + T(n/2^2)
// T(n/4) = c_2 + c_2 + c_2 + T(n/8)   =>  3 * c_2 + T(n/2^3)
// T(n/8) = c_2 + c_2 + c_2 + c_2 + T(n/16)  =>  4 * c_2 + T(n/2^4)

// general form:
// T(n) = k * c_2 + T(n/2^k)

// derive closed form:
// let n/2^k = 1    =>   n = 2^k, then log_2(n) = log_2(2^k)   =>   k = log_2(n)

// T(n) = log_2(n) * c_2 + T(1)   =>   log_2(n) * c_2 + c_1   =>   O(log n)


int main(void)
{
    printf("%d\n", power(1, 90)); // 1
    printf("%d\n", power(0, 90)); // 0
    printf("%d\n", power(2, 3)); // 8
    printf("%d\n", power(2, 10)); // 1024

    return 0;
}