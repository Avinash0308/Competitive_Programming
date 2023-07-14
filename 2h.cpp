#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long test;
    cin >> test;

    while (test--)
    {
        long long num;
        cin >> num;

        long long b = 1;
        while (b)
        {
            if ((int)log2(b) + 1 >= (int)log2(num / b) + 1)
            {

                cout << (num - b) + 1 << endl;
                b = 0;
            }
            else
            {
                b++;
            }
        }
    }
    return 0;
}