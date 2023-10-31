#include<bits/stdc++.h>
using namespace std;
long long int find(vector<int> price, vector<int> category){
    int n = price.size();
    unordered_map<int,vector<int>> m;
    long long int sum = 0;
    for(int i = 0; i<n; i++){
        m[category[i]].push_back(price[i]);
        sum += price[i];
    }
    vector<int> miny;
    for(auto it:m){
        int ele = *min_element(it.second.begin(),it.second.end());
        miny.push_back(ele);
    }
    sort(miny.begin(),miny.end());
    long long int ans = 0;
    long long int cur = 0;
    for(int i = 0; i<miny.size(); i++){
        ans += (i+1)*miny[i];
        cur += miny[i];
    }
    sum -= cur;
    ans += (sum)*miny.size();
    return ans;
}
int main(){
    cout<<find({3,2,4},{2,1,2});
    return 0;
}
