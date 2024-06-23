#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string t = s;
        ll low = 1, high = n;
        ll cur = n;
        for(cur = n; cur>=1; cur--){
            queue<ll> ind;
            ll pos = 1;
            for(ll i = 0; i<n && pos; i++){
                while(!(ind.empty()) && ind.front() < i ) ind.pop();
                ll change = ind.size();
                if(change%2){
                    if(s[i] == '0') s[i] = '1';
                    else s[i] = '0';
                }
                if(s[i] == '0'){
                    if(n-i >= cur){
                        ind.push(i+cur-1);
                    }
                    else{
                        pos = 0;
                    }
                }
            }
            if(pos){
                break;
            }
            s = t;
        }
        cout<<cur<<endl;
    }
    return 0;
}
