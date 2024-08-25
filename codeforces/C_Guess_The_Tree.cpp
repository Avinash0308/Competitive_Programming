#include <bits/stdc++.h>
using namespace std;
#define ll long long ll
ll q(ll a, ll b)
{
}

void take(ll a, ll b, vector<ll> &v, vector<pair<ll, ll>> &ans)
{
    cout << "? " << a << " " << b << endl;
    cout.flush();
    ll x;
    cin >> x;
    if (x == a || x == b)
    {
        ans.push_back({a, b});
        v[x] = 1;
        v[b] = 1;
        return;
    }
    if (v[a] && v[x])
    {
        take(x, b, v, ans);
    }
    else
    {
        take(a, x, v, ans);
        take(x, b, v, ans);
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n + 1);
        vector<pair<ll, ll>> ans;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i + 1; j <= n; j++)
            {
                if (v[j])
                    continue;
                take(i, j, v, ans);
            }
        }
        cout << "! ";
        for (auto i : edges)
        {
            cout << i.first << " " << i.second << " ";
        }
        cout << endl;
        cout.flush();
    }
    return 0;
}