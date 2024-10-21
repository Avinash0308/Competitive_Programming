#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll mod = 1e9 + 7, p = 31;
    string x, y;
    cin >> x >> y;
    ll n = x.size(), m = y.size();
    ll s, r;
    cin >> s >> r;

    vector<ll> a1(26,0), a2(26,0);
    for(auto i:x){
        a1[i-'a']++;
    }
    for(auto i:y){
        a2[i-'a']++;
    }
    for(ll i=0;i<26;i++){
        if(a1[i] && a2[i] == 0){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }

    unordered_map<ll, ll> mp;
    for (ll i = 0; i < m; i++)
    {
        if(a1[y[i]-'a'] == 0){
            continue;
        }
        ll hash = 0, po = 1;
        for (ll j = i; j < m; j++)
        {
            if(a1[y[j]-'a'] == 0){
                j = m;
                continue;
            }
            hash = (hash + (y[j] - 'a' + 1) * po) % mod;
            po = (po * p) % mod;
            mp[hash] = s;
        }
    }
    reverse(y.begin(), y.end());
    for (ll i = 0; i < m; i++)
    {
        if(a1[y[i]-'a'] == 0){
            continue;
        }
        ll hash = 0, po = 1;
        for (ll j = i; j < m; j++)
        {
            if(a1[y[j]-'a'] == 0){
                j = m;
                continue;
            }
            hash = (hash + (y[j] - 'a' + 1) * po) % mod;
            po = (po * p) % mod;
            if (mp.count(hash) == 0)
                mp[hash] = r;
            else
                mp[hash] = min(mp[hash], r);
        }
    }
    bool pos = true;
    vector<ll> dp(n, INT_MAX);
    for (ll i = n - 1; i >= 0; i--)
    {
        ll hash = 0, po = 1;
        ll val = INT_MAX;
        for (ll j = i; j < n; j++)
        {
            hash = (hash + (x[j] - 'a' + 1) * po) % mod;
            po = (po * p) % mod;
            ll val1 = INT_MAX;
            if (mp.count(hash) != 0)
            {
                val1 = mp[hash];
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
        cout << dp[0] << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}