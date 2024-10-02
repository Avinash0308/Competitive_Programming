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
        for(ll i = 0 ; i<n; i++){
            cin>>v[i];
        }
        for(ll i = n-3; i>=0; i--){
            v[n-2] -= v[i];
        }
        v[n-1] -= v[n-2];
        cout<<v[n-1]<<endl;
    }
    return 0;
}