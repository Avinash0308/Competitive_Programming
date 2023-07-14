#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

string solve(vector<int> a)
{
    if (a.size() == 1)
    {
        if (a[0] == 1)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
    else
    {
        set<vector<int>> s(a.begin(), a.end());
        if (s.size() == 1)
        {
            if (a[0] == 1)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] % 2 != a[i + 1] % 2)
                {
                    return "YES";
                }
                if ((a[i] % 2 == 1) && (a[i + 1] % 2 == 1))
                {
                    int m = __gcd(a[i], a[i + 1]);
                    if (m == 1)
                    {
                        return "YES";
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            return "NO";
        }
    }
}
int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cout << solve(a);
    return 0;
}