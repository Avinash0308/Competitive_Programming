#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int n, vector<int> &visit, vector<vector<int>> &adj)
{
    queue<int> q;
    unordered_map<int, int> mp;
    q.push(ind);
    visit[ind] = 1;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j])
            {
                mp[i]++;
                if (!visit[j])
                {
                    visit[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    int x = int(mp.size()) - 1;
    for (auto i : mp)
    {
        if (i.second != x)
        {
            cout << i.first << " " << i.second << endl;
            return 0;
        }
    }
    return 1;
}
int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges)
{
    // code here
    vector<vector<int>> adj(v + 1, vector<int>(v + 1, 0));
    for (auto edge : edges)
    {
        adj[edge[0]][edge[1]] = 1;
        adj[edge[1]][edge[0]] = 1;
    }
    int ans = 0;
    vector<int> visit(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (visit[i])
            continue;
        ans += solve(i, v, visit, adj);
    }
    return ans;
}

int main()
{
    vector<vector<int>> v = {{1, 2}, {1, 3}, {3, 2}};
    cout << findNumberOfGoodComponent(3, 3, v) << endl;
    return 0;
}