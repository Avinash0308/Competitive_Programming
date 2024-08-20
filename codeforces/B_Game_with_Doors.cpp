#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll l, r;
        cin>>l>>r;
        ll a,b;
        cin>>a>>b;
        if(r<a) cout<<1<<endl;
        else if(b<l) cout<<1<<endl;
        else if(l<=a && b<=r){
            ll val = 0;
            val = b-a;
            if(l < a) val++;
            if(b < r) val++;
            cout<<val<<endl;
        }
        else if(a<=l && r<=b){
            ll val = 0;
            val = r-l;
            if(a < l) val++;
            if(r < b) val++;
            cout<<val<<endl;
        }
        else if(l <= a){
            ll val = 0;
            val = r-a;
            if(r < b) val++;
            if(l<a) val++;
            cout<<val<<endl;
        }
        else if(a <= l){
            ll val = 0;
            val = b-l;
            if(b < r) val++;
            if(a < l) val++;
            cout<<val<<endl; 
        }
    }
    return 0;
}