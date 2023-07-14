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
        int x;
        cin >> n;
        int v[n];
        // vector<int> w;
        v[0] = 0;
        v[1] = 1;
        int u = 1;
        for (int i = 2; i < n; i++)
        {
            v[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            // w.push_back(x);
            v[x] = v[x] + 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0 || v[i] % i == 0)
            {
                continue;
            }
            else
            {
                u = 0;
                cout << "NO" << endl;
                break;
            }
        }
        if (u)
        {   
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
