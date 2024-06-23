#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    vector<ll> v(t);
    for(ll i = 0; i<t; i++){
        cin>>v[i];
    }
    ll moves = 0;
    for(ll i = 1; i<t; i++){
        ll zero = 0;
        moves += max(zero,v[i-1]-v[i]);
        v[i] = max(v[i],v[i-1]);
    }
    cout<<moves<<endl;
    return 0;
}