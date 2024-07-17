#include <bits/stdc++.h>
using namespace std;

void solve(unordered_map<int, vector<int>> &mp, vector<int> &visit, int ind, int n, vector<int> &cur, vector<int> &ans)
{
    if (visit[ind] <= cur[0])
        return;
    visit[ind] = cur[0];
    cout<<ind<<" ";
    cur.push_back(ind);
    if (ind == n)
    {
        ans = cur;
        cur.pop_back();
        return;
    }
    int x = mp[ind].size();
    for (int i = 0; i < x; i += 2)
    {
        cur[0] += mp[ind][i + 1];
        solve(mp, visit, mp[ind][i], n, cur, ans);
        cur[0] -= mp[ind][i + 1];
    }
    cur.pop_back();
}
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    vector<int> visit(n + 1, INT_MAX);
    unordered_map<int, vector<int>> mp;
    for (auto i : edges)
    {
        mp[i[0]].push_back(i[1]);
        mp[i[0]].push_back(i[2]);
        mp[i[1]].push_back(i[0]);
        mp[i[1]].push_back(i[2]);
    }
    vector<int> ans;
    vector<int> cur;
    cur.push_back(0);
    solve(mp, visit, 0, n, cur, ans);
    if (ans.size() == 0)
        return {-1};
    return ans;
}

int main()
{
    vector<vector<int>> edge = {{1,2,2},{2,5,5},{2,3,4},{1,4,1},{4,3,3},{3,5,1}};
    vector<int> ans = shortestPath(5,6,edge);
    cout<<endl;
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}