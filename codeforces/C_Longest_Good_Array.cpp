#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll l, r;
        cin>>l>>r;
        if(l == r) cout<<1<<endl;
        else{
            ll val = (r-l)*2;
            ll i = 1, j = 100000;
            while(i<=j){
                ll mid = (i+j)/2;
                if((mid*mid) + mid <= val){
                    i = mid+1;
                }
                else{
                    j = mid-1;
                }
            }
            cout<<j+1<<endl;
        }
    }
    return 0;
}