#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000009
int main()
{
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        vector<ll> divv;
        if (n % 2 == 1)
        {
            for (int i = 1; i <= n / 2; i += 2)
            {
                if (n % i == 0)
                {
                    divv.push_back(i);
                    v.push_back((n * i) % mod);
                }
            }
            divv.push_back(n);
        }
        else
        {
            for (int i = 1; i <= n / 2; i++)
            {
                if (n % i == 0)
                {
                    divv.push_back(i);
                    
                    v.push_back((n * i) % mod);
                }
            }
            divv.push_back(n);
        }
    }

    return 0;
}
