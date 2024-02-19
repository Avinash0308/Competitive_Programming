#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int big, low;
        if(n%2){
            big = n-1, low =1;
        }
        else{
            big = n; low = 1;
        }
        while(big > 0 || low <= n){
            if(big > 0)cout<<big<<" ";
            if(low<=n) cout<<low<<" ";
            big -= 2;
            low+=2;
        }
        cout<<endl;
    }
return 0;
}