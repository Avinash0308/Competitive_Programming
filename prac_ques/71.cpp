#include <iostream>
#include <bits/stdc++.h>
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
        string s;
        cin >> s;
        if (n % 2 == 0)
        {
            vector<int> cha(26);
            for (int i = 0; i < n; i++)
            {
                cha[(int)s[i] - 97]++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (cha[i] % 2 == 1)
                {
                    cout << "No" << endl;
                    goto end;
                }
            }
            cout << "Yes" << endl;
        end:
            continue;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}