#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> v(n);
        for(int i = 0; i<n; i++){
            cin>>v[i];
        }
        long long int avg = accumulate(v.begin(),v.end(),0);
        avg/=n;
        int pos = 1;
        for(int i = n-1; i>=0 && pos; i--){
            if(v[i] > avg){
                pos = 0;
                break;
            }
            else{
                v[i-1] -= (avg-v[i]);
            }
        }
        if(pos) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
return 0;
}