#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        vector<ll> x(n);
        for(ll i = 0; i<n; i++){
            cin>>x[i];
        }
        ll a = 0, b = 0;
        ll c = 0, d= 0;
        for(ll i = 0; i<n; i++){
            if(v[i] == 1 && x[i] == 1){
                a++;
            }
            else if(v[i] == -1 && x[i] == -1){
                b++;
            }
            else if(v[i] == 1) c++;
            else if(x[i] == 1) d++;
        }
        if(c > d){
            ll temp = c;
            c = d;
            d = temp;
        }
        c += a;
        d -= b;
        if(c <= d){
            cout<<c<<endl;
        }
        else{
            while(c > d){
                c--;
                d++;
            }
            cout<<c<<endl;
        }
    }
    return 0;
}