#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m, k;
        cin>>n>>m>>k;
        ll max = n/m;
        if(n%m) max++;
        ll val = n-max;
        if(val <= k) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}