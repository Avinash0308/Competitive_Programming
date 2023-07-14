#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        pair<char, int> pari;
        vector<pair<char, int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[j].first == s[i])
                {
                    v[j].second++;
                    goto end;
                }
            }
            pari.first = s[i];
            pari.second = 1;
            v.push_back(pari);
        end:
            continue;
        }
        if (v.size() > n / 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].second % 2 == 1)
                {
                    cout << "NO" << endl;
                    goto last;
                }
            }
            for (int i = 0; i < v.size(); i++)
            {
                int x = 0, q = 0;
                for (int j = 0; j < n; j++)
                {
                    if (v[j].first == v[i].first && q != 0)
                    {
                        if ((j - x) % 2 == 1)
                        {
                            goto me;
                        }
                    }
                    if (v[j].first == v[i].first && q == 0)
                    {
                        x = j;
                        q++;
                    }
                }
                cout << "NO" << endl;
                goto last;

            me:
                if (i == v.size() - 1)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    continue;
                }
            }
        }
    last:
        continue;
    }
    return 0;
}