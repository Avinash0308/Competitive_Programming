#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long isSumPalindrome(long long n)
    {
        // code here
        int j = 1;
        while (j <= 5)
        {
            vector<int> v;
            long long int x = n;
            int a;
            while (x != 0)
            {
                a = x % 10;
                v.push_back(a);
                x /= 10;
            }
            x = 0;
            for (int i = v.size() - 1; i >= 0; i++)
            {
                x = x * 10 + v[i];
            }
            n += x;
            x = n;
            vector<int> b;
            while (x != 0)
            {
                a = x % 10;
                b.push_back(a);
                x /= 10;
            }
            int flag = 1;
            for (int i = 0; i < b.size(); i++)
            {
                if (b[i] != b[b.size() - i - 1])
                {
                    break;
                    flag = 0;
                }
            }
            if (flag)
            {
                return n;
            }
        }
        return -1;
    }
};
int main()
{
    Solution c;
    cout << c.isSumPalindrome(23);
    return 0;
}