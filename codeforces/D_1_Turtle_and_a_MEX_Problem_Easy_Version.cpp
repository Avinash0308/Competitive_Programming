#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll maxy = 0;
        vector<vector<ll>> v(n, vector<ll>(2));
        for (ll i = 0; i < n; i++)
        {
            ll len;
            cin >> len;
            unordered_map<ll, ll> mp;
            for (ll j = 0; j < len; j++)
            {
                ll value;
                cin >> value;
                mp[value]++;
            }
            ll val = 0;
            ll ind = 0;
            while (ind < 2)
            {
                if (mp.count(val) == 0)
                {
                    v[i][ind] = val;
                    ind++;
                }
                val++;
            }
            maxy = max(maxy,v[i][1]);
        }
        ll ans = 0;
        if(m > maxy){
            ans = maxy*(maxy+1);
            ans += ((m-maxy)*(maxy+1+m))/2;
        }
        else ans = maxy*(m+1);
        cout<<ans<<endl;
    }
    return 0;
}