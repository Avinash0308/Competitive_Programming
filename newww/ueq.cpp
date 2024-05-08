#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin,s);
    unordered_map<char,int> mp;
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(s[i] == ' ') continue;
        mp[s[i]]++;
    }
    int low = INT_MAX, high = INT_MIN;
    char a , b;
    for(auto c:mp){
        if(c.second > high){
            high = c.second;
            b = c.first;
        }
        if(c.second == high){
            int first = (int)c.first;
            int second = (int)b;
            if(first >= 97 && first <= 122){
                if(second >= 97 && second <= 122){
                    if(first < second){
                        b = c.first;
                    }
                }
                else{
                    b = c.first;
                }
            }
            else if(second >= 65 && second <= 90){
                if(second > first){
                    b = c.first;
                }
            }
        }
        if(c.second <low){
            low = c.second;
            a = c.first;
        }
        else if(c.second == low){
            int first = (int)c.first;
            int second = (int)a;
            if(first >= 97 && first <= 122){
                if(second >= 97 && second <= 122){
                    if(first < second){
                        a = c.first;
                    }
                }
                else{
                    a = c.first;
                }
            }
            else if(second >= 65 && second <= 90){
                if(second > first){
                    a = c.first;
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(s[i] == a){
            s[i] = b;
        }
        else if(s[i] == b){
            s[i] = a;
        }
    }
    cout<<s<<endl;
    return;
}

int main(){
    solve();
    return 0;
}