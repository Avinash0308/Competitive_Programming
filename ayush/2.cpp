#include<bits/stdc++.h>
using namespace std;



int main(){
    int n = 5;
    vector<string> v(5);
    for(int i = 0; i<5; i++){
        cin>>v[i];
    }
    char s = v[0][1];
    int equal = 1;
    for(int i = 1; i<n; i++){
        if(s == v[i][1]) equal++;
    }
    if(equal == 5) cout<<"NO"<<endl;
    else{
        unordered_map<char,int> mp;
        mp['A'] = 1;
        mp['T'] = 10;
        mp['J'] = 11;
        mp['Q'] = 12;
        mp['K'] = 13;
        for(int i = 2; i<=9; i++){
            mp[char(i+48)] = i;
        }
        vector<int> t;
        for(int i = 0; i<n; i++){
            t.push_back(mp[v[i][0]]);
        }
        sort(t.begin(),t.end());
        int pos = 1;
        for(int i = 1; i<5 && pos; i++){
            if(t[i]-t[i-1] != 1) pos = 0;
        }
        if(pos) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}