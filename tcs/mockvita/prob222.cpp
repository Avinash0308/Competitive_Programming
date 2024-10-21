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
    vector<vector<ll>> dp(n, vector<ll>(2, INT_MAX));
    for (ll i = n - 1; i >= 0; i--)
    {
        string cur;
        ll cnt = INT_MAX, val = INT_MAX;
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
            if (val1 == INT_MAX){
                continue;
            }
            if (j != n - 1)
                val1 += dp[j + 1][0];
            ll str_cnt = 1;
            if (j != n - 1)
                str_cnt += dp[j + 1][1];
            if (cnt > str_cnt)
            {
                cnt = str_cnt;
                val = val1;
            }
            else if (cnt == str_cnt)
            {
                val = min(val, val1);
            }
        }
        if (val == INT_MAX)
        {
            pos = false;
            break;
        }
        else
        {
            dp[i] = {val, cnt};
        }
    }
    if (pos)
        cout << dp[0][0];
    else
        cout << "Impossible";
    return 0;
}