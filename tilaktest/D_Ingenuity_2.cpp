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
        unordered_map<char,ll> mp;
        mp['N'] = 0;
        mp['S'] = 0;
        mp['E'] = 0;
        mp['W'] = 0;
        for(auto i:s){
            mp[i]++;
        }
        ll first = abs(mp['N'] - mp['S']);
        ll sec = abs(mp['E'] - mp['W']);
        if(first %2 || sec %2) cout<<"NO"<<endl;
        else if(((mp['N'] == 1 && mp['S'] == 1) && (mp['E'] < 1 && mp['W'] < 1)) || ((mp['E'] == 1 && mp['W'] == 1) && (mp['N'] < 1 && mp['S'] < 1))) cout<<"NO"<<endl;
        else{
            ll u = 0, v = 0, x = 0, y  = 0;
            int r = 0, h = 0;
            string ans;
            for(auto i:s){
                if(i == 'N'){
                    if(u > v){
                        ans.push_back('H');
                        h = 1;
                        v++;
                    }
                    else if(u == v){
                        if(r == 0){
                            r = 1;
                            ans.push_back('R');
                            u++;
                        }
                        else{
                            h = 1;
                            ans.push_back('H');
                            v++;
                        }
                    }
                    else {ans.push_back('R'); u++; r = 1;}
                }
                else if(i == 'S'){
                    if(u > v){
                        ans.push_back('R');
                        u--;
                        r = 1;
                    }
                    else if(u == v){
                        if(r == 0){
                            r = 1;
                            ans.push_back('R');
                            u--;
                        }
                        else{
                            h = 1;
                            ans.push_back('H');
                            v--;
                        }
                    }
                    else {ans.push_back('H');v--;h = 1;}
                }
                else if(i == 'E'){
                    if(x > y){
                        ans.push_back('H');
                        y++;
                        h = 1;
                    }
                    else if(x == y){
                        if(r == 0){
                            r = 1;
                            ans.push_back('R');
                            x++;
                        }
                        else{
                            h = 1;
                            ans.push_back('H');
                            y++;
                        }
                    }
                    else{
                        ans.push_back('R');
                        x++;
                        r = 1;
                    }

                }
                else{
                    if(x > y){
                        ans.push_back('R');
                        x--;
                        r = 1;
                    }
                    else if(x == y){
                        if(r == 0){
                            r = 1;
                            ans.push_back('R');
                            x--;
                        }
                        else{
                            h = 1;
                            ans.push_back('H');
                            y--;
                        }
                    }
                    else {ans.push_back('H'); y--;h = 1;}
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}