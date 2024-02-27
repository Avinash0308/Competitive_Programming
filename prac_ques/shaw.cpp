#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 32, 4};
    int last = INT_MIN;
    int n = arr.size();
    vector<int> ans;
    bool pos = true;
    for (int i = 0; i < n; i++)
    {
        string cur;
        if (last > arr[i])
        {
            pos = false;
            break;
        }
        if (arr[i] == 0)
        {
            ans.push_back(0);
            last = 0;
            continue;
        }
        while (arr[i])
        {
            int val = arr[i] % 10;
            cur.push_back(char(val + 10));
            val /= 10;
        }
        reverse(cur.begin(), cur.end());
        int value = INT_MAX;
        string cur2;
        for (int j = 0; j < cur.size(); j++)
        {
            cur2.push_back(cur[j]);
            while (stoi(cur2) >= last)
            {
                value = min(value, stoi(cur2));
                cur2.erase(0, 1);
            }
        }
        ans.push_back(value);
        last = value;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
vector<int> solve(vector<int> &arr)
{
    vector<int> arr = {3, 32, 4};
    int last = INT_MIN;
    int n = arr.size();
    vector<int> ans;
    bool pos = true;
    for (int i = 0; i < n; i++)
    {
        string cur;
        if (last > arr[i])
        {
            pos = false;
            break;
        }
        if (arr[i] == 0)
        {
            ans.push_back(0);
            last = 0;
            continue;
        }
        while (arr[i])
        {
            int val = arr[i] % 10;
            cur.push_back(char(val + 10));
            val /= 10;
        }
        reverse(cur.begin(), cur.end());
        int value = INT_MAX;
        string cur2;
        for (int j = 0; j < cur.size(); j++)
        {
            cur2.push_back(cur[j]);
            while (cur2.size() && stoi(cur2) >= last)
            {
                value = min(value, stoi(cur2));
                cur2.erase(0, 1);
            }
        }
        ans.push_back(value);
        last = value;
    }
    if(!pos) return {-1};
    return ans;
}