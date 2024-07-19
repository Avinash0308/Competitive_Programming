#include <bits/stdc++.h>
using namespace std;
int getDis(pair<int, int> a, pair<int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
bool solve(vector<vector<int>> &v)
{
    int n = v.size();
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        s.insert({v[i][0], v[i][1]});
        s.insert({v[i][2], v[i][3]});
    }
    if (s.size() != 4)
        return false;
    set<int> dist;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        for (auto j = s.begin(); j != s.end(); j++)
        {
            if (*i != *j)
            {
                dist.insert(getDis(*i, *j));
            }
        }
    }
    if (dist.size() > 3)
        return false;
    int distance[3];
    int i = 0;
    for (auto it = dist.begin(); it != dist.end(); it++)
    {
        distance[i++] = *it;
    }
    if (dist.size() == 2)
        return (2 * distance[0] == distance[1]);
    return (distance[0] + distance[1] == distance[2]);
}

int main()
{
    vector<vector<int>> v = {{0, 0, 0, 3}, {2, 0, 0, 0}, {2, 2, 2, 0}, {0, 2, 2, 2}};
    if (solve(v))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}