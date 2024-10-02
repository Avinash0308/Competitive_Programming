#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool solve(string &s, unordered_map<string,ll> &mp, string &ans, ll n){
    if(mp.count(s) != 0){
        return mp[s];
    }
    bool ret;
    string x = s + "0";
    cout<<"? "<<x<<endl;
    cout.flush();
    cin>>ret;
    if(ret) mp[x] = 1;
    else mp[x] = 0;
    if(ret){
        mp[s] = 1;
        if(s.size() == n){
            ans = s;
            return true;
        }
        else{
            string x = s + "0";
            if(solve(x,mp,ans,n)){
                return true;
            }
            else{
                x = s + "1";
                if(solve(x,mp,ans,n)){
                    return true;
                }
                else{
                    x = "1" + s;
                    if(solve(x,mp,ans,n)){
                        return true;
                    }
                    else{
                        x = "0" + s;
                        if(solve(x,mp,ans,n)){
                            return true;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
    }
    else{
        mp[s] = 0;
        return false;
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        unordered_map<string,ll> mp;
        string a = "";
        string ans;
        solve(a,mp,ans,n);
        cout<<"! "<<ans<<endl;
        cout.flush();
    }
    return 0;
}