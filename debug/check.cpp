#include <bits/stdc++.h>
using namespace std;

int compare(string &a, string &b)
{
    int n = a.size(), m = b.size();
    int i = n - 1, j = m - 1, ans = 0;
    while ((i >= 0) || (j >= 0))
    {
        char x, y;
        if (i >= 0)
            x = a[i];
        else
            x = '0';
        if (j >= 0)
            y = b[j];
        else
            y = '0';
        if (x > y)
            ans = 1;
        else if (x < y)
            ans = -1;
        i--, j--;
    }
    return ans;
}
int compareVersion(string &a, string &b)
{
    int n = a.size(), m = b.size();
    int i = 0, j = 0, ans = 0;
    string x, y;
    while ((i < n) || (j < m))
    {
        x = "0", y = "0";
        while (i < n && a[i] != '.')
            x += a[i++];
        while (j < m && b[j] != '.')
            y += b[j++];
        if (ans = compare(x, y))
            return ans;
        i++, j++;
    }
    return ans;
}

int main()
{
    string a = "1.01", b = "1.001";
    cout << compareVersion(a, b) << endl;
    return 0;
}