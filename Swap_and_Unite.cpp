#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<vector<pair<ll, ll>>> v(26);
        vector<ll> tot(26);
        ll n = s.size();
        for (ll i = 0; i < n; i++)
        {
            ll start = i;
            while (i < n - 1 && s[i] == s[i + 1])
                i++;
            v[s[i] - 'a'].push_back({start,i});
            tot[s[i] - 'a'] += i - start + 1; 
        }
        ll ans = INT_MAX;
        for (ll i = 0; i < 26; i++)
        {
            if (v[i].size() == 0)
                continue;
            if (v[i].size() == 1)
            {
                ans = 0;
                break;
            }
            else
            {
                ll high = ll(v[i].size())-1, low = 0;
                ll mov = 0;
                while(low<high){
                    ll diff = v[i][high].first - v[i][high-1].second-1;
                    tot[i] -= (v[i][high].second-v[i][high].first + 1);
                    while(low<high && diff){
                        ll len = v[i][low].second - v[i][low].first + 1;
                        if(diff >= len){
                            diff -= len;
                            low++;
                            mov += len;
                        }
                        else{
                            v[i][low].first += diff;
                            mov += diff;
                            diff = 0;
                        }
                    }
                    high--;
                }
                ans = min(ans,mov);
            }
        }
        cout << ans << endl;
    }
    return 0;
}