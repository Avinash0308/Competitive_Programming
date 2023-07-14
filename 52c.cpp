#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v;
        vector<int> value_size;
        vector<int> total;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            value_size.push_back(k);
            vector<int> vv;
            for (int j = 0; j < k; j++)
            {
                int a;
                cin >> a;
                total.push_back(a);
                vv.push_back(a);
            }
            v.push_back(vv);
        }
        set<vector<int>> s_total(total.begin(), total.end());
        if (s_total.size() < 5)
        {
            cout << "No" << endl;
            goto end;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    vector<int> check(v[i]);
                    check.insert(check.end(), v[j].begin(), v[j].end());
                    set<vector<int>> con(check.begin(), check.end());
                    if (con.size() == 5)
                    {
                        cout << "Yes" << endl;
                        goto end;
                    }
                }
            }
        }
        cout << "No" << endl;
    end:
        continue;
    }
}