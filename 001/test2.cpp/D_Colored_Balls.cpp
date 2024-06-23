#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll mod = 998244353;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector < vector<vector<ll>> mp(n);
    sort(v.begin(), v.end());
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        mp[i].push_back({v[i], v[i]});
        ans = (ans + v[i]) % mod;
        for (ll j = i + 1; j < n; j++)
        {
            for (auto val : mp[j])
            {
                ll cur = (val.first - val.second + max(v[i], val.second)) % mod;
                ans = (ans + cur) % mod;
                mp[i].push_back({cur, abs(val.second - v[i])});
            }
        }
    }
    cout << ans << endl;
    return 0;
}