#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k, d;
        cin >> n >> m >> k >> d;
        vector<vector<ll>> v(n, vector<ll>(m));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        vector<ll> ans(n);
        vector<ll> col(m);
        for (ll i = 0; i < n; i++)
        {
            set<pair<ll, ll>> s;
            col[0] = 1;
            ll ind = 0;
            s.insert({col[0], ind});
            for (ll j = 1; j < m; j++)
            {
                if (j-1 > d)
                {
                    s.erase({col[j - d - 2], j - d - 2});
                }
                col[j] = (*s.begin()).first + v[i][j] + 1;
                s.insert({col[j], j});
            }
            s.clear();
            ans[i] = col[m - 1];
        }
        ll result = 0;
        for (ll i = 0; i < n && i < k; i++)
        {
            result += ans[i];
        }
        ll cur = result;
        for (ll i = k; i < n; i++)
        {
            cur -= ans[i - k];
            cur += ans[i];
            result = min(result, cur);
        }
        cout << result << endl;
    }
    return 0;
}