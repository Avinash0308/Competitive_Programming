#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int num_dish, num_dis;
        cin >> num_dish >> num_dis;
        vector<int> a(num_dish);
        vector<int> b(num_dish);
        for (int i = 0; i < num_dish; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < num_dish; i++)
        {
            cin >> b[i];
        }
        int dis = 0;
        map<int, int> m;
        for (int i = 0; i < num_dish; i++)
        {
            m[a[i]]++;
            if (m[a[i]] == 1)
            {
                dis++;
            }
        }
        if (dis < num_dis)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<pair<int, int>> p;
            int ans = 0;
            for (int i = 0; i < num_dish; i++)
            {
                pair<int, int> p1;
                p1.first = a[i];
                p1.second = b[i];
                p.push_back(p1);
            }
            int x = 0;
            while (x < num_dis)
            {
                for (int i = 0; i < p.size(); i++)
                {
                    while (p[i].second == -1 && i < p.size())
                    {
                        i++;
                    }
                    if (i < p.size())
                    {
                        ans += p[i].second;
                        p[i].second = -1;
                        x++;
                    }
                    while (p[i].first == p[i + 1].first && i < p.size() - 1)
                    {
                        i++;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
