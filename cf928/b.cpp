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
        string s;
        cin >> s;
        string m;
        cin >> m;
        string cur = "";
        int x = 0, y = 0;
        int val;
        while (y <= n - 1)
        {
            if (x == 0)
            {
                cur.push_back(s[y]);
                if (y == n - 1)
                {
                    val = y;
                    x++;
                }
                else if (s[y + 1] == '1' && m[y] == '0')
                {
                    val = y;
                    x++;
                }
                else
                    y++;
            }
            else
            {
                cur.push_back(m[y]);
                y++;
            }
        }
        string ans = cur;
        int some = 1;
        while (val - 1 >= 0 && s[val] == m[val - 1])
        {
            some++;
            val--;
        }
        cout << ans << endl;
        cout << some<< endl;
    }
    return 0;
}