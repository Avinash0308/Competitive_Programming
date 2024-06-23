#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<ll> v(m);
        for(ll i = 0; i<m; i++){
            cin>>v[i];
        }
        string c;
        cin>>c;
        sort(c.begin(),c.end());
        sort(v.begin(),v.end());
        ll ind = 0;
        for(ll i = 0; i<m; i++){
            s[v[i]-1] = c[ind];
            ind++;
            while(i<m-1 && v[i] == v[i+1]) i++;
        }
        cout<<s<<endl;
    }
    return 0;
}