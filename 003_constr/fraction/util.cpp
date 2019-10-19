#include <iostream>
#include <random>

int gcd(int a, int b);
int random(int a, int b);
std::random_device rd;
std::mt19937 mt(rd());
template <typename T> int sgn(T val);


/** 
 * Find greatest common divisor
*/
int gcd(int a, int b) 
{
    if (b == 0) 
        return a; 
    return gcd(b, a % b);       
}


/**
 * Generate random integer
*/
int rnd(int a, int b)
{
    std::uniform_int_distribution<int> distribution(a, b);
    int dice_roll = distribution(mt);
}


/**
 * Sign of a number
*/
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}