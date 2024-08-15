#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, c;
        cin>>a>>b>>c;
        if(a+b < c || a+c < b || c+a<b) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}