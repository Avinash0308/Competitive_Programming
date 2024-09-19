#include <bits/stdc++.h>
using namespace std;

int solve(int ind, unordered_map<int, vector<int>> &mp, unordered_map<int, vector<int>> &xp, vector<int> &cur, unordered_map<int, int> &visit, unordered_map<int, int> &h, unordered_map<int, int> &parent)
{
    cur.push_back(ind);
    xp[ind] = cur;
    visit[ind] = 1;
    int he = 0;
    for (auto i : mp[ind])
    {
        if (visit[i])
            continue;
        parent[i] = ind;
        he = max(he, solve(i, mp, xp, cur, visit, h, parent));
    }
    cur.pop_back();

    return h[ind] = he + 1;
}
vector<int> findLongest(int n, int q, vector<vector<int>> &edges, vector<vector<int>> &queries)
{
    // code here
    unordered_map<int, vector<int>> mp;
    for (auto i : edges)
    {
        mp[i[0]].push_back(i[1]);
        mp[i[1]].push_back(i[0]);
    }
    unordered_map<int, vector<int>> xp;
    vector<int> cur;
    unordered_map<int, int> visit;
    unordered_map<int, int> h;
    unordered_map<int, int> parent;
    parent[1] = -1;
    solve(1, mp, xp, cur, visit, h, parent);
    vector<int> ans;
    for (auto q : queries)
    {
        int i = 0;
        while (i < xp[q[0]].size() && i < xp[q[1]].size())
        {
            if (xp[q[0]][i] == xp[q[1]][i])
                i++;
            else
                break;
        }
        int ind = xp[q[0]][i - 1];
        int res = h[ind];
        int dis = 0;
        while (ind != -1)
        {
            res = max(res, dis + h[ind]);
            ind = parent[ind];
            cout<<ind<<endl;
            dis++;
        }
        ans.push_back(res);
    }
    return ans;
}

int main()
{
    vector<vector<int>> edge = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {5, 6}};
    vector<vector<int>> q = {{4, 6}};
    vector<int> ans = findLongest(6, 1, edge, q);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}