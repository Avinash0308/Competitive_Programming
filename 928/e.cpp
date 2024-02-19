#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        if (k <= ((n + 1) / 2))
        {
            cout << (2 * k) - 1 << endl;
        }
        else
        {
            k -= ((n + 1) / 2);
            long long int val = 2;
            long long int lar = n / val;
            long long int inf = (lar + 1) / 2;
            while (k > inf)
            {
                k -= inf;
                val *= 2;
                lar = n / val;
                inf = (lar + 1) / 2;
            }
            long long int ans = ((2 * k) - 1) * val;
            cout << ans << endl;
        }
    }
    return 0;
}