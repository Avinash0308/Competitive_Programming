#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    long long int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        vector<int> x;

        for (int i = 0; i < n; i++)
        {
            int q = 1;

            while (v[i] == v[i + 1] && i < n-1)
            {
                q++;
                i++;
            }

            x.push_back(q);
        }
        sort(x.begin(), x.end());
        if (x[x.size() - 1] == x[x.size() - 2])
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
