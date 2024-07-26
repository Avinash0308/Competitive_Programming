#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll one = n/4;
        n -= one*4;
        cout<<one+(n/2)<<endl;
    }
    return 0;
}