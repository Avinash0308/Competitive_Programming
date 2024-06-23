#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string v;
        cin>>v;
        if(n == 2){
            if(v[0]=='0' && v[1] == '0' ) cout<<0<<endl;
            else if(v[0] == '0') cout<<v[1]<<endl;
            else cout<<v<<endl;
        }
        else if(n == 3){
            int a = (v[0]-'0'), b= v[1]-'0', c = v[2]-'0';
            int m = (a*10) + b + c;
            int n = (a*10 + b) * c;
            int o = a + (b*10) + c;
            int p = a * (b*10 + c);
            cout<<min({n,m,p,o})<<endl;
        }
        else{
            ll zero = 0;
            for(ll i = 0; i<n && !zero; i++){
                if(v[i] == '0') zero = 1;
            }
            if(zero) cout<<0<<endl;
            else {
                ll sum = 0;
                for(ll i = 0; i<n; i++){
                    sum += v[i]-'0';
                    if(v[i] == '1') sum--;
                }
                ll ans = INT_MAX;
                for(ll i = 0;i <n-1; i++){
                    ll val = (v[i]-'0')*10 + v[i+1]-'0';
                    ll cur = val;
                    if(v[i] != '1') cur -= v[i]-'0';
                    if(v[i+1] != '1') cur -= v[i+1]-'0';
                    ans = min(ans,cur+sum);
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}