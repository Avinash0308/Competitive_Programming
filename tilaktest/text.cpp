#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    if (a.first == b.first)
        return a.second > b.second;
    else
        return false;
}
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    int n = difficulty.size(), m = worker.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({difficulty[i], profit[i]});
    }
    sort(v.begin(), v.end(), comp);
    vector<int> x1, x2;
    for (int i = 0; i < n; i++)
    {
        x1.push_back(v[i].first);
        x2.push_back(v[i].second);
        int ind = i;
        while (i < n - 1 && v[ind].second >= v[i + 1].second)
            i++;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int ind = lower_bound(x1.begin(), x1.end(), worker[i] + 1) - x1.begin();
        cout<<ind<<endl;
        if (!ind)
            continue;
        cout << x2[ind - 1] << endl;
        ans += x2[ind - 1];
    }
    return ans;
}
int main()
{
    vector<int> a = {68, 35, 52, 47, 86};
    vector<int> b = {67, 17, 1, 81, 3};
    vector<int> c = {92, 10, 85, 84, 82};
    cout << maxProfitAssignment(a, b, c) << endl;
    return 0;
}