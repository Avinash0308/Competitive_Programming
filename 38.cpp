#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> count(string s)
    {
        // code here.
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if ((int)s[i] >= 65 && (int)s[i] <= 90)
            {
                a++;
            }
            if ((int)s[i] >= 97 && (int)s[i] <= 122)
            {
                b++;
            }
            if ((int)s[i] >= 48 && (int)s[i] <= 57)
            {
                c++;
            }
            else
            {
                d++;
            }
        }
    }
};
int main()
{

    return 0;
}