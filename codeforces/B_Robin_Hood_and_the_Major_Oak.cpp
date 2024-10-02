#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll ans = max(1ll,n-k+1);
        if(ans%2){
            ll odd = (n-ans+2)/2;
            if(odd%2) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else{
            ll odd = (n-ans+1)/2;
            if(odd%2) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}