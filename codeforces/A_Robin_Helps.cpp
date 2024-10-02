#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        ll ans = 0;
        ll cur = 0;
        for(ll i = 0; i<n; i++){
            if(v[i] >= k){
                cur += v[i];
            }
            else if(v[i] == 0 && cur){
                cur--;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}