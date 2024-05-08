#include<bits/stdc++.h>
using namespace std;

void pattern(){
    int n;
    cin>>n;
    vector<vector<char>> v(n,vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == n/2){
                v[i][j] = '#';
            }
            else{
                v[i][j] = ' ';
            }
            if(j == i || j == n-1-i){
                v[i][j] = '*';
            }
            
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n ;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return;
}

int main(){
    pattern();
    return 0;
}