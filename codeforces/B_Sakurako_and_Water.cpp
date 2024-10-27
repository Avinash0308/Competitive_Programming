#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> v(n,vector<ll>(n));
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<n; j++){
                cin>>v[i][j];
            }

        }
        ll ans = 0;
        for(ll i = 0; i<n; i++){
            ll cur = 0;
            for(ll j = 0, k = i; j<n && k<n; j++,k++){
                cur = min(cur,v[j][k]);
            }
            if(cur < 0) ans += abs(cur);
        }
        for(ll i = 1; i<n; i++){
            ll cur = 0;
            for(ll j = i, k = 0; j<n && k<n; j++,k++){
                cur = min(cur,v[j][k]);
            }
            if(cur < 0){
                ans += abs(cur);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}