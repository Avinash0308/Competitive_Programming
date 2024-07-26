#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    ll mod = 1e9+7;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n = s.size();
        unordered_map<ll,ll> mp;
        ll ans = 0;
        mp[0] = 1;
        ll one = 0, zero = 0;
        for(ll i = 0; i<n; i++){
            if(s[i] == '1') one++;
            else zero++;
            ll req = one-zero;
            if(mp.count(req) != 0){
                ans = (ans + (mp[req]*(n-i))%mod)%mod;
            }
            mp[one-zero] = (mp[one-zero] + i + 2)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}