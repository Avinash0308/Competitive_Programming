#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        int val = 1;
        ll ind = n-1;
        if(k == 0) val = 0;
        k -= n;
        while(k > 0 && ind){
            k -= ind;
            val++;
            if(k>0){
                k -= ind;
                val++;
            }
            ind--;
        }
        cout<<val<<endl;
    }
    return 0;
}