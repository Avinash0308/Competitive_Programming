#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(1100, vector<int>(33, 0));
vector<int> p(1100, 0);
vector<vector<int>> x(1100);
int comp = 0;
void pre()
{
    for (int j = 2; j * j <= 1001; j++)
    {
        if (p[j])
            continue;
        for (int i = j*j; i <= 1001; i += j)
        {
            v[i][j] = 1;
            v[i][i/j] = 1;
            p[i] = 1;
        }
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            if (i == 1 && j == 1)
            {
                x[i].push_back(1);
                continue;
            }
            else if (i == j)
            {
                continue;
            }
            int count = 0;
            for (int k = 2; k <= 32; k++)
            {
                if (v[i][k] == v[j][k] && v[i][k] == 1)
                {
                    count++;
                    break;
                }
            }
            if (!count)
            {
                x[i].push_back(j);
                x[j].push_back(i);
            }
        }
    }
}
int MaxDiff(vector<int> &A, int n)
{
    if (comp == 0)
    {
        comp = 1;
        pre();
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[A[i]] = i;
    }
    int ans = -1;
    for (int i = 0; n - i - 1 > ans; i++)
    {
        for (auto j : x[A[i]])
        {
            if (mp.count(j) != 0)
            {
                ans = max(ans, abs(mp[j] - i));
                cout<<j<<" "<<A[i]<<endl;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {60, 6, 26, 42, 44, 44, 14, 27, 65, 8, 94, 93, 52, 12};
    cout << MaxDiff(v, 14) << endl;
    return 0;
}