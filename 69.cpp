#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findLeastGreater(vector<int> &arr, int n)
    {
        vector<int> x(n);
        map<int, int> m;
        int max = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= max)
            {
                max = arr[i];
                x[i] = -1;
            }
            else
            {
                x[i] = arr[i];
            }
            m[arr[n - i - 1]] = n - i - 1;
        }
        vector<int> res(n);
        map<int, int>::iterator it;
        for (int i = 0; i < n; i++)
        {
            if (x[i] != -1)
            {
                it = m.find(arr[i]);
                it++;
                while (i > it->second && it != m.end())
                {
                    it++;
                }
                if (it != m.end())
                {
                    res[i] = it->first;
                }
            }
            else
            {
                res[i] = -1;
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}