#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool sameFreq(string s)
    {
        // code here
        map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        map<int, int> f;
        for (auto i : m)
        {
            f[i.second]++;
        }
        int x = 0;
        int an = 0 , am = 0;
        int as = 0, ay = 0;
        for (auto i : f)
        {
            x++;
            if (x == 1)
            {
                an = i.first;
                as = i.second;
            }

            if (x == 2)
            {
                am = i.first;
                ay = i.second;
            }
        }
        if (x > 2)
        {
            return false;
        }
        else if (x == 1)
        {
            return true;
        }
        else
        {
            if(an == 1 && as == 1){
                return true;
            }
            else if(am - an == 1 && ay == 1){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
int main()
{

    return 0;
}