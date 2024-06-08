#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;
        ll val = 1;
        for(ll i = 0; i<=31; i++){
            if((val&x) != (val&y)){
                break;
            }
            else{
                val<<=1;
            }
        }
        cout<<val<<endl;
    }
    return 0;
}