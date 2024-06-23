#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<long long int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        unordered_map<long long int, int> mp;
        unordered_map<long long int, pair<long long int, long long int>> branch;
        int br = 0;
        for (int i = 0; i < n; i++)
        {
            long long int val = a[i] + i + 1;
            if (mp.count(val) == 0)
            {
                mp[val]++;
                if(mp.count(val-1) != 0 && mp.count(val+1) != 0){
                    int left_b = mp[val-1];
                    int right_b = mp[val+1];
                    branch[left_b].second = branch[right_b].second;
                    branch[right_b].first = branch[left_b].first;
                    branch[br] = {branch[left_b].first, branch[right_b].second};
                    mp[val] = br;
                    br++;
                }
                else if(mp.count(val-1) != 0){
                    int left_b = mp[val-1];
                    branch[left_b].second = val;
                    branch[br] = {branch[left_b].first,val};
                    mp[val] = br;
                    br++;
                }
                else if(mp.count(val+1) != 0){
                    int right_b = mp[val+1];
                    branch[right_b].first = val;
                    branch[br] = {val,branch[right_b].second};
                    mp[val] = br;
                    br++;
                }
                else{
                    mp[val] = br;
                    branch[br] = {val,val};
                    br++;
                }
            }
            else
            {
                long long int brr = mp[val];
                long long int left = branch[brr].first;
                if(left-1 >= val + 1){
                mp[left-1] = brr;
                branch[brr].first = left-1;
                }
            }
        }
        vector<long long int> res;
        for (auto i : mp)
        {
            res.push_back(i.first);
        }
        sort(res.begin(), res.end());
        int ress = res.size();
        for (int i = ress - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}