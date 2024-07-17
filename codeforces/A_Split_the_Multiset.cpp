#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;

        cin>>n>>k;
        if(n == 1) cout<<0<<endl;
        else if(n <= k) cout<<1<<endl;
        else{
            int count = 0;
            int step = 0;
            ll val = n;
            while(count < n){
                count += k-1;
                step++;
                val -= (k-1);
                if(val == 1){
                    count++;
                }
            }
            cout<<step<<endl;
        }
    }
    return 0;
}