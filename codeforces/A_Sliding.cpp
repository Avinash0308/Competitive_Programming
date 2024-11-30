#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m, r, c;
        cin>>n>>m>>r>>c;
        ll ans = m-c + ((2*m - 1)*(n-r));
        cout<<ans<<endl;
    }
    return 0;
}