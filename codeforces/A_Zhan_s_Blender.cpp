#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll x, y;
        cin>>x>>y;
        ll a = (n+y-1)/y;
        ll b = (n+x-1)/x;
        cout<<max(a,b)<<endl;
    }
    return 0;
}