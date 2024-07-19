#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll ans = 0;
        ll sum = 0, val = 0;
        ll cur = -1;
        for (ll i = 0; i < n; i++)
        {
            val = 0;
            for (ll j = i; j < n; j++)
            {

                val += v[j];
                if (val > x)
                {
                    val = 0;
                }
                else
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}