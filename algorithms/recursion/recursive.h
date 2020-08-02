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

// Draw nth-iter for Tower of Hanoi problem
void drawTowerOfHanoi (int n, char src, char spr, char dst) {
    if (n == 1) {
        std::cout << "Move: " << src << " -> " << dst << std::endl;
    } else {
        drawTowerOfHanoi (n - 1, src, dst, spr);
        drawTowerOfHanoi (1, src, spr, dst);
        drawTowerOfHanoi (n - 1, spr, src, dst);
    }
}