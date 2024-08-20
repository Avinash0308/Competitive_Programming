#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<ll> v;
        for(ll i = 0; i<n; i++){
            ll a;
            cin>>a;
            v.insert(a);
        }
        if(v.size() > 2) cout<<"NO"<<endl;
        else if(v.size() == 1) cout<<"YES"<<endl;
        else{
            int first = *(v.begin());
            v.erase(v.begin());
            int sec = *(v.begin());
            if(first + 1 < sec) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    }
    return 0;
}