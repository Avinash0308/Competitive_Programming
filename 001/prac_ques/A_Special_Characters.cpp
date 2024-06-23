#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            string ans;
            int ind = 0;
            for (int i = 0; i < n / 2; i++)
            {
                ind %= 26;
                ans.push_back(char(ind + 65));
                ans.push_back(char(ind + 65));
                ans.push_back(char(ind + 65));
                ind++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}