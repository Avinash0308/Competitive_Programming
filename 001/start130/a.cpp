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
        vector<ll> ind;
        for(ll i= 1; i<n; i+=2){
            if(s[i] != s[i-1]){
                if(ind.empty() || s[ind.back() - 1] != s[i]){
                    ind.push_back(i+1);
                }
                else{
                    ind.push_back(i);
                }
            }
        }
        ll m = ind.size();
        cout<<m<<endl;
        for(auto i:ind){
            cout<<i<<" ";
        }
        if(m)cout<<endl;
    }
    return 0;
}