#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll s, d, k;
        cin>>s>>d>>k;
        ll bun = (s+d)*2;
        ll cheese = s + d*2;
        ll patties = s + d*2;
        if(k + 1 <= bun && k <= cheese && k <= patties) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}