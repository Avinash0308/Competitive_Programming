#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, q;
        cin>>n>>q;
        string a, b;
        cin>>a;
        cin>>b;
        vector<vector<int>> v(q,vector<int>(2));
        for(int i = 0; i<q; i++){
            cin>>v[i][0]>>v[i][1];
        }
        vector<vector<int>> x(n,vector<int>(26,0)), y(n,vector<int>(26,0));
        for(int i= 0; i<n; i++){
            if(i != 0){
                x[i] = x[i-1];
                y[i] = y[i-1];
            }
            x[i][a[i]-'a']++;
            y[i][b[i]-'a']++;
        }
        for(int i = 0; i<q; i++){
            int diff = 0;
            for(int j = 0; j<26; j++){
                int x1 = x[v[i][1]-1][j], x2 = y[v[i][1]-1][j];
                if(v[i][0]>1){
                    x1 -= x[v[i][0]-2][j];
                    x2 -= y[v[i][0]-2][j];
                }
                diff += abs(x1-x2);
            }
            cout<<diff/2<<endl;
        }
    }
    return 0;
}