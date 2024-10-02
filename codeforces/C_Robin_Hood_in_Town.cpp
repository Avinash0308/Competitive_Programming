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
        sort(v.begin(),v.end());
        if(n<=2) cout<<-1<<endl;
        else{
            ll ind = n/2;
            ll x = v[n/2];
            ll tot = 0;
            for(ll i=  0; i<n; i++){
                tot += v[i];
            }
            ll req = (2*x)*n;
            cout<<max(req - tot+1,0ll)<<endl;
        }
    }
    return 0;
}