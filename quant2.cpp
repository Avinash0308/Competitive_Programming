#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int N, int K, vector<int> &seat, int &out_n)
{
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i = 1; i<=N; i++){
        p.push(i);
    }
    for(int i = 0; i<K; i++){
        if(seat[i] == 0){
            ans.push_back(p.top());
            p.pop();
        }
        else{
            p.push(seat[i]);
        }
    }
    out_n = ans.size();
    return ans;
}
int main()
{
    vector<int> seat = {0,0,2,1,0,1,0,1,0,1,0,1};
    int si = 0;
    vector<int> ans = solution(5,12,seat,si);
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}