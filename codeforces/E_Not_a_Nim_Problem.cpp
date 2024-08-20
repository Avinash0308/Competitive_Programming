#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v;
        ll ones = 0;
        for(ll i = 0; i<n; i++){
            ll a;
            cin>>a;
            if(a == 1) ones++;
            else v.push_back(a);
        }
        char turn;
        if(ones%2) turn = 'b';
        else turn = 'a';
        
    }
    return 0;
}