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
        ll val = sqrt(n);
        bool pos = true;
        if(val *val == n){
            for(ll i = 0; i<val && pos; i++){
                for(ll j = 0; j<val &&pos ; j++){
                    char x = s[i*val + j];
                    if((i == 0 || i == val-1 || j == 0 || j == val-1)){
                        if(x == '0') pos = false; 
                    }
                    else {
                        if(x == '1') pos = false;
                    }
                }
            }
            if(pos) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}