#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int i = 0;
        int n = s.size();
        int val = 0;
        while(i<n){
            val++;
            while(i<n-1 && s[i] == s[i+1])i++;
            i++;
        }
        if(val == 1) cout<<1<<endl;
        else if(val == 2 && s[0] == '1')cout<<2<<endl;
        else{
            cout<<val-1<<endl;
        }
    }
    return 0;
}