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
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            vector<int> vv;
            for (int j = 0; j < k; j++)
            {
                int a;
                cin >> a;
                vv.push_back(a);
            }
            v.push_back(vv);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i][0] == 5)
            {
                cout << "Yes" << endl;
                goto end;
            }
            else
            {
                vector<int> me;
                for (int k = 1; k < v[i].size(); k++)
                {
                    me.push_back(v[i][k]);
                }
                for (int j = i + 1; j < n; j++)
                {
                    if (v[i][0] + v[j][0] < 5)
                    {
                        goto st;
                    }
                    else
                    {
                        for (int p = 1; p < v[j].size(); p++)
                        {
                            me.push_back(v[i][p]);
                        }
                        set<vector<int>> ss(me.begin(), me.end());
                        if (ss.size() == 5)
                        {
                            cout << "Yes" << endl;
                            goto end;
                        }
                    }
                st:
                    continue;
                }
            }
        }
        cout<<"No"<<endl;
    end:
        continue;
    }
    return 0;
}