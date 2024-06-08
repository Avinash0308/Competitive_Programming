#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;
        ll one = y/2;
        ll sec = 7*one;
        if(y%2){
            one++;
            sec += 11;
        }
        if(x <= sec) cout<<one<<endl;
        else{
            x -= sec;
            x += 14;
            one += x/15;
            cout<<one<<endl;
        }
    }
    return 0;
}