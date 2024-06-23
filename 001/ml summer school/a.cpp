#include <bits/stdc++.h>
using namespace std;

int main()
{
    string r, b, k;
    cin >> r;
    vector<int> v(26);
    for (auto i : r)
    {
        v[i - 'a']++;
    }
    int ind = 0;
    for (int i = 0; i < 26; i++)
    {
        while (v[i])
        {
            if (r[ind] - 'a' == i)
            {
                if (b.empty() || b.back() > r[ind])
                {
                    v[i]--;
                    k.push_back(r[ind]);
                    ind++;
                }
                else
                {
                    k.push_back(b.back());
                    b.pop_back();
                }
            }
            else
            {
                v[r[ind] - 'a']--;
                b.push_back(r[ind]);
                ind++;
            }
        }
    }
    while (!b.empty())
    {
        k.push_back(b.back());
        b.pop_back();
    }
    cout << k << endl;
    return 0;
}