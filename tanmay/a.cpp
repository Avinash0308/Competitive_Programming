#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> solve(int ind,unordered_map<int,vector<int>> &e, vector<int> &col, unordered_map<int,int> &mp, int &ans, vector<int> &visit){
    unordered_map<int,int> mp1;
    if(visit[ind]) return mp1;
    visit[ind] = 1;
    for(auto i:e[ind]){
        unordered_map<int,int> x = solve(i,e,col,mp,ans,visit);
        int cur = x.size() + mp.size();
        for(auto j:x){
            if(mp[j.first] == j.second){
                cur--;
            }
            mp1[j.first] += j.second;
        }
        ans = max(ans,cur);
    }
    visit[ind] = 0;
    mp1[col[ind]]++;
    return mp1;
}
int GetAnswer(int N, int M, int C, vector<vector<int>> edges, vector<int> col){
    unordered_map<int,vector<int>> e;
    for(int i = 0; i<M; i++){
        e[edges[i][0]].push_back(edges[i][1]);
        e[edges[i][1]].push_back(edges[i][0]);
    }
    unordered_map<int,int> mp;
    for(int i = 0; i<N; i++){
        mp[col[i]]++;
    }
    int ans = 0;
    vector<int> visit(n+1);
    solve(1,e,col,mp,ans,visit);
    return ans;
}
int main(){
    int n, m, c;
    cin>>n>>m>>c;
    vector<int> col(n);
    for(int i= 0; i<n; i++){
        cin>>col[i];
    }
    cout<<GetAnswer(1,e,col,mp,ans,visit)<<endl;
    return 0;
}