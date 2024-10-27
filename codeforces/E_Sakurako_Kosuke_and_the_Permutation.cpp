#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        vector<ll> vis(n);
        ll ans = 0;
        for(ll i = 0; i<n; i++){
            ll ind = i;
            ll cnt = 0;
            while(!vis[ind]){
                vis[ind] = 1;
                ind = v[ind] - 1;
                cnt++;
            }
            ans += (cnt-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}