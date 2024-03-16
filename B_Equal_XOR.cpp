#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> v(n);
        vector<ll> x(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i];
        }
        for(ll i = 0; i<n; i++){
            cin>>x[i];
        }
        sort(v.begin(),v.end());
        sort(x.begin(),x.end());
        vector<ll> a;
        vector<ll> b;
        for(ll i =0; i<n-1; i++){
            if(v[i] == v[i+1]){
                a.push_back(v[i]);
                a.push_back(v[i]);
            }
            if(x[i] == x[i+1]){
                b.push_back(x[i]);
                b.push_back(x[i]);
            }
        }
        ll si = a.size();
        while(si > 2*k){
            a.pop_back();
            a.pop_back();
            b.pop_back();
            b.pop_back();
            si -= 2;
        }
        for(ll i = 0; i<n && si < 2*k; i++){
            if((i>0 && v[i] == v[i-1] )|| (i<n-1 && v[i] == v[i+1])){
                continue;
            }
            a.push_back(v[i]);
            b.push_back(v[i]);
            si++;
        }
        for(ll i = 0; i<2*k; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for(ll i = 0; i<2*k; i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}