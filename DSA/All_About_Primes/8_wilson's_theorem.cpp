// Wilson's theorem states that a natural number n > 1 is a prime number if and only if the product of all the positive integers less than n is one less than a multiple of n.

// (product of all i = 1 to p - 1) % p = p - 1
// (p - 1)! % p = p - 1
// p = 7 ---> (1 * 2 * 3 * 4 * 5 * 6) % 7 = 720 % 7 = 6

// In other words, any number n is a prime number if, and only if, (n − 1)! + 1 is divisible by n.
// i.e. n = 7 ---> (6! + 1) % 7 = (720 + 1) % 7 = 721 % 7 = 0

// prime numbers follows this property

// Problem Link
// https://www.hackerearth.com/problem/algorithm/fact-count-a6300182/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}