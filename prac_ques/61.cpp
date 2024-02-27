#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> prefixCount(int n, int q, string li[], string query[])
    {
        // code here
        vector<int> v;
        for (int i = 0; i < q; i++)
        {
            int x = 0;
            for (int j = 0; j < n; j++)
            {
                char xx[sizeof(li[j]) + 1];
                strcpy(xx, li[j].c_str());
                int a = sizeof(query[i]);
                char s[a + 1];
                strncpy(s, xx, a);
                if (s == query[i])
                {
                    x++;
                }
            }
            v.push_back(x);
        }
        return v;
    }
};
int main()
{

    return 0;
}