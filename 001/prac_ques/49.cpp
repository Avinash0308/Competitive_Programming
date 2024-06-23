#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long prime(long long x)
{
    if (x <= 1)
    {
        return 0;
    }
    if (x % 2 == 0 || x % 3 == 0)
    {
        return 0;
    }
    for (int i = 5; i * i <= x; i += 6)
    {
        if (x % i == 0 || (x + 2) % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

long long minNumber(long long arr[], long long N)
{
    long long x = accumulate(arr, arr + N, 0);
    if (prime(x))
    {
        return 0;
    }
    else
    {

        long long i = x / 6;
        if (x % 6 == 0)
        {
            long long z = (6 * i) + 1;
            if (prime(z))
            {
                return z - x;
            }
            z = (6 * (i + 1)) - 1;
            if (prime(z))
            {
                return z - x;
            }
            z = (6 * (i + 1)) + 1;

            return z - x;
        }
        else
        {
            long long z = (6 * (i + 1)) - 1;
            if (prime(z))
            {
                return z - x;
            }
            z = (6 * (i + 1)) + 1;
            if (prime(z))
            {
                return z - x;
            }
        }
    }
}
int main()
{

    return 0;
}