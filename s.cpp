#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string solve(string a, string b){
    string ans;
    int n = b.size(), m = a.size();
    for(int i = 0; i<n; i++){
        if(b[i] == 'F') continue;
        while(ans.size() < i){
            ans.push_back('A');
        }
        int j = i;
        while(j<ans.size() && j<i+m){
            if(ans[j] != a[j-i]) return "-1";
            j++;
        }
        while(j<i+m){
            ans.push_back(a[j-i]);
            j++;
        }

    }
    while(ans.size() < n+m-1) ans.push_back('A');
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
return 0;
}