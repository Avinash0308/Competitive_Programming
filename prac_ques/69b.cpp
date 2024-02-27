#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findLeastGreater(vector<int> &arr, int n)
    {
        vector<int> res(n);
        vector<pair<int, int>> p;
        int max = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= max)
            {
                max = arr[i];
                res[i] = -1;
            }
            pair<int, int> m;
            m.first = arr[i];
            m.second = i;
            p.push_back(m);
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++)
        {
            if (res[p[i].second] != -1)
            {
                int j = i + 1;
                while ((p[j].first <= p[i].first || p[j].second < p[i].second) && j < n)
                {
                    j++;
                }
                if (j != n)
                {
                    res[p[i].second] = p[j].first;
                }
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}