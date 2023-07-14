#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A = 0, B = 0, P = 0, Q = 0;
    cin >> A >> B >> P >> Q;
    if (A == P && B == Q)
    {
        std::cout << 0 << std::endl;
    }

    else if (((A + B) % 2 == 0 && (P + Q) % 2 == 0 || (A + B) % 2 != 0 && (P + Q) % 2 != 0) && (A != P && B != Q))
    {
        std::cout << 2 << std::endl;
    }
    else
    {
        std::cout << 1 << std::endl;
    }
    return 0;
}