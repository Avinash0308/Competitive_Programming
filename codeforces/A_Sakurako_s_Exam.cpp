#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        ll tot = a + 2*b;
        if(a%2) cout<<"NO"<<endl;
        else if(a == 0 && b%2 == 1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}