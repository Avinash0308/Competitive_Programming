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
        ll miny = 1e9+7;
        for(ll i = 0; i<n-1; i++){
            miny = min(miny,max(v[i],v[i+1]));
        }
        cout<<miny-1<<endl;
    }
    return 0;
}