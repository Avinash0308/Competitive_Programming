#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, a, b;
        cin>>n>>a>>b;
        if(b >= 2*a){
            cout<<n*a<<endl;
        }
        else{
            ll ans = (n/2)*b;
            if(n%2) ans += a;
            cout<<ans<<endl; 
        }
    }
    return 0;
}