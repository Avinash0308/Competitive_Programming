#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long mod = 998244353;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<long long> cube(n);
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            res = (res + v[i]) % mod;
            cube[i] = res;
        }
        long long fin = 0;
        for (int i = 0; i < n; i++)
        {
            res = 0;
            for (int j = i; j < n; j++)
            {
                if (i == 0)
                {
                    res = cube[j];
                }
                else
                {
                    res = cube[j] - cube[i - 1];
                }
                fin += (res * res * res) % mod;
            }
        }
        cout << fin << endl;
    }
}