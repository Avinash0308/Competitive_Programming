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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> d(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> d[i];
        }
        vector<ll> f(k);
        for (ll i = 0; i < k; i++)
        {
            cin >> f[i];
        }
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        ll maxy = 0, ind = -1, count = 0, second = 0;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > maxy)
            {
                second = maxy;
                maxy = a[i] - a[i - 1];
                ind = i;
                count = 1;
            }
            else if (a[i] - a[i - 1] == maxy)
            {
                second = maxy;
                count++;
            }
            else if (a[i] - a[i - 1] > second)
                second = a[i] - a[i - 1];
        }
        if (count > 1)
        {
            cout << maxy << endl;
        }
        else
        {
            ll cur = a[ind] - a[ind - 1];
            ll x = 0, y = k - 1;
            while (x < m && y >= 0)
            {
                ll complexity = d[x] + f[y];
                if (complexity > a[ind - 1] && complexity < a[ind])
                {
                    ll dif1 = complexity - a[ind - 1];
                    ll dif2 = a[ind] - complexity;
                    cur = min(cur, max(dif1, dif2));
                    if (dif1 == dif2)
                        break;
                    if (dif1 > dif2)
                        y--;
                    else
                        x++;
                }
                else if (complexity < a[ind - 1])
                {
                    x++;
                }
                else
                {
                    y--;
                }
            }
            cur = max(cur, second);
            cout << cur << endl;
        }
    }
    return 0;
}