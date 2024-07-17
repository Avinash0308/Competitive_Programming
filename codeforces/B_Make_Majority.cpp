#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string str;
        for(int i = 0; i<n; i++){
            if(s[i] == '1') str += "1";
            else{
                while(i+1<n && s[i+1] == '0') i++;
                str += "0";
            }
        }
        int one = 0, zero = 0;
        for(int i = 0; i<str.size(); i++){
            if(str[i]=='0') zero++;
            else one++;
        }
        if(zero >= one) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}