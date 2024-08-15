#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0; i<n; i++){
        cin>>v[i];
    }
    ll x = 0, y = 0, z = 0;
    for(ll i =n -1; i>=0; i--){
        ll cur = v[i] + max(y,z);
        z = y;
        y = x;
        x = cur;
    }
    cout<<max(x,y)<<endl;
    return 0;
}