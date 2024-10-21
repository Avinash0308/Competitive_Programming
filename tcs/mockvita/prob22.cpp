#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class ary
{
public:
    ll val;
    vector<ary *> child;
    ary(ll val)
    {
        this->val = val;
        child.resize(26, NULL);
    }
};
int main()
{
    ll mod = 1e9 + 7, p = 31;
    string x, y;
    cin >> x >> y;
    ll n = x.size(), m = y.size();
    ll s, r;
    cin >> s >> r;
    ary *xa = new ary(0);
    for (ll i = 0; i < m; i++)
    {
        ary *ya = xa;
        for (ll j = i; j < m; j++)
        {
            if (ya->child[y[j] - 'a'] == NULL)
            {
                ya->child[y[j] - 'a'] = new ary(s);
            }
            ya = ya->child[y[j] - 'a'];
        }
    }
    for (ll i = m - 1; i >= 0; i--)
    {
        ary *ya = xa;
        for (ll j = i; j >= 0; j--)
        {
            if (ya->child[y[j] - 'a'] == NULL)
            {
                ya->child[y[j] - 'a'] = new ary(r);
            }
            else
            {
                ya->child[y[j] - 'a']->val = min(ya->child[y[j] - 'a']->val, r);
            }
            ya = ya->child[y[j] - 'a'];
        }
    }
    bool pos = true;
    vector<vector<ll>> dp(n, vector<ll>(2, INT_MAX));
    for (ll i = n - 1; i >= 0; i--)
    {
        ary *ya = xa;
        ll cnt = INT_MAX, val = INT_MAX;
        for (ll j = i; j < n; j++)
        {
            ll val1 = INT_MAX;
            if (ya->child[x[j]-'a'] != NULL)
            {
                val1 = ya->child[x[j]-'a']->val;
                ya = ya->child[x[j]-'a'];
            }
            else break;
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
        cout << dp[0][0] << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}