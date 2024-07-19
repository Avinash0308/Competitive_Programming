#include <bits/stdc++.h>
using namespace std;

void solve(string &s, string &t)
{
    int n = s.size(), m = t.size();
    if (m > n)
    {
        cout << 0 << endl;
        return;
    }
    else if (m == n)
    {
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    int last = -1;
    string cur;
    for (int i = 0; i < n; i++)
    {
        cur.push_back(s[i]);
        if (i >= m - 1)
        {
            if (cur == t)
            {
                ans += i - m + 1 - last;
                ans += n - 1 - i;
                last = i - m + 1;
            }
            cur.erase(cur.begin());
        }
    }
    cout << ans << endl;
    return;
}

int main()
{

    string s, t;
    cin >> s >> t;
    solve(s, t);
    return 0;
}