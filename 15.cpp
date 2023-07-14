#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        pair<char, int> pari;
        vector<pair<char,int>> v;
        for(int i = 0; i<n ; i++){
            for(int j= 0; j<i ; j++){
                if(v[j].first == s[i]){
                    v[j].second ++;
                    goto end;
                }
            }
            pari.first = s[i];
            pari.second = 1;
            v.push_back(pari);
            end: 
            continue;
        }
        if(v.size() > n/2){
            cout<<"NO"<<endl;
            
        }
        else{
            for(int i = 0; i<v.size() ; i++){
                if(v[i].second%2 == 1){
                    cout<<"NO"<<endl;
                    goto last;
                }
            }
            cout<<"YES"<<endl;
        }
        last:
    }
return 0;
}