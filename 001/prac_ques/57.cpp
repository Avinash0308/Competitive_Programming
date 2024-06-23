#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int test;
    cin >> test;
    while (test--)
    {
        long long int n, k, gd;
        cin >> n >> k;
        vector<long long int> v;
        for (int i = 0; i < n; i++)
        {
            long long int x;
            cin >> x;
            v.push_back(x);
            if (i == 0)
            {
                gd = x;
            }
            gd = __gcd(gd, x);
        }
        long long int d;
        long long int j, i;
        for (i = 1, j = 0; i <= k && j < n; i++)
        {
            d = v[j];
            do
            {
                d = __gcd(d, v[j]);
                j++;
            } while (d != gd && j < n);
            if (d != gd)
            {
                cout << "NO" << endl;
                goto end;
            }
        }
        if (i - 1 == k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    end:
        continue;
    }
    return 0;
}
