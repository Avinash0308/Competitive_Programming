#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n == 1) cout<<1<<endl;
        else if(n%2 == 0) cout<<-1<<endl;
        else{
            for(ll i = 2; i<=n; i+=2){
                cout<<i<<" ";
            }
            cout<<1<<" ";
            for(ll i = n; i>1; i-=2){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}