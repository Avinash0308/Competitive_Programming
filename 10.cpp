#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int test;
    cin>>test;
    while(test--){
        long long int n;
        cin>>n;
        string s;
        cin>>s;
        int u = 1;
        int x = (int)s[0]; 
        for(int i = 1; i<n ; i++){
            if((int)s[i] == x){
                continue;
            }
            else{
                u = 0;
                break;
            }
        }
        if(u){
            cout<<"0"<<endl;
        }
        else if(!u){
            vector<int> v;
            if((int)s[0] == 1){
                v.push_back(1); 
            }
            for(int i = 1; i<n ; i++){
                
            }
        }
    }
return 0;
}