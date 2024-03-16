#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int t;
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
        sort(v.begin(), v.end());
        sort(x.begin(), x.end());
        ll ans = 0;
        ll a = 0, b = m - 1;
        while (a < n && b >= 0)
        {
            if (v[a] + x[b] <= k)
            {
                ans += (b + 1);
                a++;
            }
            else
            {
                b--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}