#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int test;
    cin >> test;
    while (test--)
    {
        long long int n;
        cin >> n;
        string s;
        cin >> s;
        int v = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && (int)s[i + 1] == '0')
            {
                v++;
                i += 1;
            }
        }
        cout << v << endl;
        return 0;
    }
}