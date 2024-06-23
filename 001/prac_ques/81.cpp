// your code goes here
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int mod = 998244353;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<long long int> cubeic(n);
        vector<long long int> square(n);
        vector<long long int> single(n);
        long long int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = (res + v[i]) % mod;
            single[i] = res;
            square[i] = (res * res) % mod;
            cubeic[i] = ((((res % mod) * (res % mod)) % mod) * (res % mod)) % mod;
        }
        res = 0;
        for (int i = 0; i < n; i++)
        {
            long long int fin;
            fin = cubeic[i];
            res = (res + ((((fin % mod) * (fin % mod)) % mod) * (fin % mod)) % mod) % mod;
        }
        long long int prev = res;
        for (int i = 1; i < n; i++)
        {
            long long int fin;
            long long int extra = (((((cubeic[i - 1] % mod) * (cubeic[i - 1] % mod)) % mod) * (cubeic[i - 1] % mod)) % mod);
            fin = ((n - i) * (extra)) % mod;
            res = (res + prev - fin) % mod;
            prev -= fin;
        }
        cout << res << endl;
    }
}