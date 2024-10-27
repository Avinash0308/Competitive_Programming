#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    ll mod = 1e9+7;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll a = 1%k, b = 1%k;
        ll ind = 1;
        while(a){
            a += b;
            swap(a,b);
            a %= k;
            b %= k;
            ind++;
        }
        cout<< (((ind%mod)*(n%mod))%mod) <<endl;
    }
    return 0;
}