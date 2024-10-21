#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    string x, y;
    cin >> x >> y;
    ll n = x.size(), m = y.size();
    ll s, r;
    cin >> s >> r;
    string y1 = y;
    reverse(y.begin(), y.end());
    bool pos = true;
    vector<ll> dp(n,INT_MAX);
    for (ll i = n - 1; i >= 0; i--)
    {
        string cur;
        ll val = INT_MAX;
        for (ll j = i; j < n; j++)
        {
            cur += x[j];
            ll val1 = INT_MAX;
            if (y.find(cur) != string::npos)
            {
                val1 = r;
            }
            if (y1.find(cur) != string::npos)
            {
                val1 = min(val1, s);
            }
            if (val1 == INT_MAX)
                continue;
            if (j != n - 1)
                val1 += dp[j + 1];
            val = min(val, val1);
        }
        if (val == INT_MAX)
        {
            pos = false;
            break;
        }
        else
        {
            dp[i] = val;
        }
    }
    if (pos)
        cout << dp[0];
    else
        cout << "Impossible";
    return 0;
}