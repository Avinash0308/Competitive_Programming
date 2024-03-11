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
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll val = 0;
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            mp[v[i]]++;
        }
        while (mp.count(val) != 0)
            val++;
        if (val == 0)
        {
            cout << n << endl;
            for (ll i = 1; i <= n; i++)
            {
                cout << i << " " << i << endl;
            }
        }
        else
        {
            ll ind = 0;
            unordered_map<ll, ll> mp;
            ll start = ind + 1;
            while (ind < n && mp.size() < val)
            {
                if (v[ind] < val)
                    mp[v[ind]]++;
                ind++;
            }
            if (mp.size() == val && ind != n)
            {
                ll end = ind;
                unordered_map<ll, ll> m;
                while (ind < n && m.size() < val )
                {
                    if (v[ind] < val)
                    {
                        m[v[ind]]++;
                    }
                    ind++;
                }
                if (m.size() == val)
                {
                    cout << 2 << endl;
                    cout << start << " " << end << endl;
                    cout << end + 1 << " " << n << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}