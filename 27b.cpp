#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int maxi = *max_element(v.begin(), v.end());
        vector<int> v1(maxi + 1, 0);
        for (int i = 0; i < n; i++)
        {
            v1[v[i]]++;
        }
        int maxi2 = *max_element(v1.begin(), v1.end());
        for (int i = 1; i <= maxi; i++)
        {
            if (maxi2 == v1[i])
                count++;
        }
        if (count > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
