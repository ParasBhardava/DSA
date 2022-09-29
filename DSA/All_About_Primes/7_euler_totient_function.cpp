// Uler’s Totient function Φ (n) for an input n is the count of numbers in {1, 2, 3, …, n} that are relatively prime(coprime) to n,
// i.e., the numbers whose GCD with n is 1.

// Theorem :
// if any number is prime then phi(n) = n-1;
// if n = p ^ x then phi(n) = p^x - p^(x-1)
// i.e., n = 32(2^5) ---> phi(n) = 2^5 - 2^4 = 16

// Or... Formula
// phi(n) = n * product of all(1 - (1/p))  where p is the prime factors of n
// phi(32) = 32 * (1 - 1/2) = 16
// We can represent any prime number in terms od multiplication of prime numbers.
// 288 = 2^5 * 3^2
// phi(288) = (2^5 - 2^4) * (3^2 - 3^1) = 16 * 6 = 96

#include <bits/stdc++.h>
using namespace std;

// using prime factors and sqrt method

// int phi(int num)
// {
//     int ans = 1;
//     for (int i = 2; i * i <= num; i++)
//     {
//         int count = 0;
//         while (num % i == 0)
//         {
//             count++;
//             num = num / i;
//         }

//         if (count != 0)
//             ans *= (pow(i, count) - pow(i, count - 1));
//     }

//     if (num >= 2) // because last num is prime and for prime num no. of coprime is (num - 1);
//         ans *= num - 1;

//     return ans;
// }

// Using Formula
// int phi(int num)
// {
//     double ans = num * 1.0;
//     for (int i = 2; i * i <= num; i++)
//     {
//         if (num % i == 0)
//         {
//             while (num % i == 0)
//                 num = num / i;

//             ans *= (1.0 - (1.0 / i));
//         }
//     }

//     if (num >= 2)
//         ans *= (1.0 - (1.0 / num));

//     return ans;
// }

const int N = 1000000;
int smallestprimeFactor[N + 1];

void createSieve()
{
    for (int i = 0; i <= N; i++)
        smallestprimeFactor[i] = i;

    for (int i = 2; i * i <= N; i++)
    {
        if (smallestprimeFactor[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (smallestprimeFactor[j] == j)
                    smallestprimeFactor[j] = i;
            }
        }
    }
}

int phi(int num)
{
    double ans = num * 1.0;
    unordered_set<int> s;
    while (num != 1)
    {
        s.insert(smallestprimeFactor[num]);
        num /= smallestprimeFactor[num];
    }

    for (int it : s)
        ans *= (1.0 - (1.0 / it));

    return ans;
}

int main()
{

    createSieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << phi(n) << "\n";
    }

    return 0;
}