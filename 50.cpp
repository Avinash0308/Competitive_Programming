#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<string>> v;
    v.push_back({"adsad","adfd","aesad"});
    v.push_back({"edsad","sdfd","asad"});
    sort(v[1].begin(),v[1].end());
    for(int i = 0; i<2  ;i++){
        for(int j = 0; j<3 ; j++){
            cout<<v[i][j]<<endl;
        }
    }
return 0;
}