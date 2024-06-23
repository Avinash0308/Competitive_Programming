#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> v(n,vector<ll>(m));
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                cin>>v[i][j];
            }
        }
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                ll val = 0;
                ll big = INT_MIN;
                if(i == 0 || v[i][j] > v[i-1][j]){ val++;if(i > 0) big = max(big,v[i-1][j]);}
                if(j == 0 || v[i][j] > v[i][j-1]) {val++;if(j > 0) big = max(big,v[i][j-1]);}
                if(i == n-1 || v[i][j] > v[i+1][j]) {val++;if(i < n-1) big = max(big,v[i+1][j]);}
                if(j == m-1 || v[i][j] > v[i][j+1]) {val++;if(j < m-1) big = max(big,v[i][j+1]);}
                if(val == 4 && big != INT_MIN){
                    v[i][j] = big;
                }
            }
        }
        for(ll i = 0 ;i<n; i++){
            for(ll j = 0; j<m; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}