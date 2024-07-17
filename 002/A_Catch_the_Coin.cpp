#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll> (2));
    for(ll i = 0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    for(ll i = 0; i<n; i++){
        ll loc = v[i][1] - abs(v[i][0]);
        if(0 - abs(v[i][0]) <= loc+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}