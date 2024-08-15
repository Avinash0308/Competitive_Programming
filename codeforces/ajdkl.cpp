#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long countWays(int n, vector<int> &arr, long long int x, long long int y, int target)
{
    // code here
    vector<vector<unordered_map<long long int, long long int>>> v(x + 1, vector<unordered_map<long long int, long long int>>(y + 1));
    if (x)
    {
        v[1][0][arr[n - 1]]++;
    }
    if (y)
    {
        v[0][1][-arr[n - 1]]++;
    }
    for (long long int i = n - 2; i >= 0; i--)
    {
        if (x)
        {
            for (long long int a = min(n - i, x) - 1; a>=0 && n - i - 1 - a <= y; a--)
            {
                cout << a << endl;
                for (auto b : v[a][n - i - 1 - a])
                {
                    v[a + 1][n - i - 1 - a][b.first + arr[i]] += b.second;
                }
            }
        }
        if (y)
        {
            for (long long int b = min(n - i, y) - 1; b>=0 && n - i - 1 - b <= x; b--)
            {
                cout << b << endl;
                for (auto a : v[n - i - 1 - b][b])
                {
                    v[n - i - 1 - b][b + 1][a.first - arr[i]] += a.second;
                }
            }
        }
    }
    return v[x][y][target];
}

int main()
{
    vector<int> v = {1, 1, 1, 1, 1};
    cout << countWays(5, v, 4, 1, 3) << endl;
    return 0;
}