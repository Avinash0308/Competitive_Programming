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
        cin >> n;
        vector<int> v(n), x(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        vector<int> temp1(n);
        for (int i = 0; i < n; i++)
        {
            temp1[v[i] - 1] = x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << temp1[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
