#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int x = 0;
        int i = 0;
        while (i < n - 1)
        {
            int j = 1;
            if ((v[i] ^ v[i + 1]) > 1)
            {
                i++;
            }
            else
            {
                while (((v[i] ^ v[i + 1]) <= 1) && i < n - 1)
                {
                    i++;
                    j++;
                }
            }

            if (j > x)
            {
                x = j;
            }
        }
        cout << n - x << endl;
    }
    return 0;
}