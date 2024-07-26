#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, x;
        cin>>n>>x;
        ll ans = 0;
        for(ll i = 1; (3*i)<=x && (3*i*i)<=n; i++){
            ll j = i;
            while(1){
                ll k = min(((n - (i*j))/(i+j)),(x-i-j));
                if(j>k) break;
                int diff = 1;
                if(j != i) diff++;
                if(k != j && k!=i) diff++;
                ll dis = k-j;
                if(diff == 1) ans += dis;
                else if(diff == 2) ans += 3*dis;
                else ans += 6*dis;
                if(i == j) ans += 1;
                else ans += 3;
                j++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}