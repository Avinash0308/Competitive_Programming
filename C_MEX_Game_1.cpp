#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        unordered_map<ll, ll> mp;
        ll zero = 0;
        for (ll i = 0; i < n; i++)
        {
            ll val;
            cin>>val;
            mp[val]++;
            if (val == 0)
                zero = 1;
        }
        if (!zero)
            cout << 0 << endl;
        else
        {
            vector<ll> v;
            vector<ll> c;
            ll miny = INT_MAX;
            for (auto i : mp)
            {
                if (i.second == 1)
                {
                    miny = min(miny, i.first);
                }
                else
                {
                    c.push_back(i.first);
                }
            }
            if (miny != INT_MAX)
                c.push_back(miny);
            sort(c.begin(), c.end());
            ll cur = 0;
            for (auto j : c)
            {
                if (j == cur)
                {
                    cur++;
                }
                else
                {
                    break;
                }
            }
            cout << cur << endl;
        }
    }
    return 0;
}