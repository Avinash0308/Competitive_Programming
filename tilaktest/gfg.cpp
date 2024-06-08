#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> matchingCnt(int n, vector<string>& X) {
        // code here
        vector<int> ans(n);
        unordered_map<char,unordered_map<int,int>> mp;
        for(int i = n-1; i>=0; i--){
            int x = X[i].size();
            for(int j = x-1; j>=0; j--){
                if((mp[X[i][j]].count(j) != 0)){
                    ans[i] += mp[X[i][j]][j];
                }
                mp[X[i][j]][j]++;
            }
        }
        return ans;
    }
int main(){
    vector<string> x = {"maaaaay","nameaaaa","isaaaaa","avinash","agrawal","aaaa","aaaaaaaaaaaaa","aaaaaa","aaaaaaa"};
    vector<int> ans = matchingCnt(9,x);
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}