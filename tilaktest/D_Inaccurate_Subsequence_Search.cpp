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
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> x(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> x[i];
        }
        ll ans = 0;
        unordered_map<ll, ll> bm;
        unordered_map<ll, ll> cur;
        for (ll i = 0; i < m; i++)
        {
            bm[x[i]]++;
        }
        ll diff = 0;
        for (ll i = 0; i < m - 1; i++)
        {
            cur[v[i]]++;
            if (bm.count(v[i]) != 0 && (bm[v[i]] >= cur[v[i]]))
                diff++;
        }
        for (ll i = m - 1; i < n; i++)
        {
            cur[v[i]]++;
            if (bm.count(v[i]) != 0 && (bm[v[i]] >= cur[v[i]]))
                diff++;
            if (diff >= k)
                ans++;
            cur[v[i - (m - 1)]]--;
            if (bm.count(v[i - (m - 1)]) != 0 && (bm[v[i - (m - 1)]] > cur[v[i - (m - 1)]]))
                diff--;
        }
        cout << ans << endl;
    }
    return 0;
}