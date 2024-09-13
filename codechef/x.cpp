#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, k;
        cin>>a>>b>>k;
        if(a < b){
            if(k%2){
                ll val = k/2;
                val *= b;
                cout<<val<<endl;
            }
            else{
                ll val = (k/2)-1;
                val *= b;
                val += a;
                cout<<val<<endl;
            }
        }
        else if( a==b){
            ll val = k/2;
            // ll val = k-1;
            val *= a;
            cout<<val<<endl;
        }
        else{
            if(k == 1) cout<<0<<endl;
            else if(k%2){
                ll val = (k/2)-1;
                val *= b;
                val += a;
                cout<<val<<endl;
            }
            else{
                ll val = k/2;
                val *= b;
                cout<<val<<endl;
            }
        }
    }
    return 0;
}