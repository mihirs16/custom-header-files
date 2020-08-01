#include <stdio.h>

// Factorial of a number
long int factorial (long int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial (n-1);
}

// Greatest Common Divisor using Euclid's Algorithm
long int greatestCommonDivisor (long int a, long int b) {
    if (a % b) {
        return (greatestCommonDivisor (b, a % b));
    }

    return b;
}