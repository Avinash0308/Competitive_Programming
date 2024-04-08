#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<ll, ll>> v(n);
        for (ll i = 0; i < n; i++)
        {
            ll val;
            cin >> val;
            v[i] = {val, i};
        }
        ll least = ((k - 1) / m) + 1;
        sort(v.begin(), v.end());
        vector<pair<ll, ll>> sec(least);
        ll large = v[least - 1].second;
        for (ll i = 0; i < least; i++)
        {
            sec[i] = {v[i].second, v[i].first};
        }
        sort(sec.begin(), sec.end());
        ll ans = 0;

        ll pur = 0;
        for (ll i = 0; i < least; i++)
        {
            sec[i].second += pur;
            if (large == sec[i].first)
            {
                ll pur_v = k - ((least - 1) * m);
                ans += (pur_v * sec[i].second);
                pur += pur_v;
            }
            else
            {
                ans += (m * sec[i].second);
                pur += m;
            }
        }
        cout << ans << endl;
    }
    return 0;
}