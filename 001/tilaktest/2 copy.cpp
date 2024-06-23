#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int n){
    vector<string> dp(n+1,0);
    for(int i = 1; i<=9; i++){
        for(int j = 1; j<=n; j++){
            if(v[i] <= n){
                
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(9);
    for(int i = 0; i<9; i++){
        cin>>v[i];
    }
    solve(v,n);
    return 0;
}