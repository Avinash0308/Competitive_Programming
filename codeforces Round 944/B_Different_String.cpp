#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int i = 0;
        while(i<n-1 && s[i] == s[i+1]) i++;
        if(i == n-1) cout<<"NO"<<endl;
        else{
            swap(s[i],s[i+1]);
            cout<<"YES"<<endl<<s<<endl;
        }
    }
    return 0;
}