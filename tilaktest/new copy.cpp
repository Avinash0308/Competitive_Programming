#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int maximumLength(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int cur = 1;
        while (i < n - 1 && nums[i] == nums[i + 1])
        {
            i++;
            cur++;
        }
        v.push_back({cur, nums[i]});
    }
    multiset<pair<int, int>> m;
    int nn = v.size();
    int cur_sum = 0;
    vector<int> ans(nn);
    unordered_map<int, int> p;
    for (int i = nn - 1; i >= 0; i--)
    {
        ans[i] = v[i].first + cur_sum;
        if (p.count(v[i].second) != 0)
        {
            ans[i] = max(ans[i], v[i].first + ans[p[v[i].second]]);
        }
        p[v[i].second] = i;
        cur_sum += v[i].first;
        m.insert(v[i]);
        if (m.size() > k)
        {
            auto val = m.begin();
            cur_sum -= (*val).first;
            m.erase(m.begin());
        }
    }
    int final = 0;
    for (int i = 0; i < nn; i++)
    {
        final = max(final, ans[i]);
    }
    return final;
}
int main()
{
    vector<int> v = {1,2,1,1,3};;
    cout<<maximumLength(v,2)<<endl;
    return 0;
}