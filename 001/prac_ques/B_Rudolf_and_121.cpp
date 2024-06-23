#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll pos = 1;
        for (ll i = 0; (i < n - 2 )&& pos; i++)
        {
            if (((v[i + 1] - (v[i] * 2)) >= 0) && (v[i + 2] >= v[i]))
            {
                v[i + 1] -= (v[i] * 2);
                v[i + 2] -= v[i];
                v[i] = 0;
            }
            else
            {
                pos = 0;
            }
        }
        if (pos)
        {
            if (v[n - 2] || v[n - 1])
                pos = 0;
        }
        if (pos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}