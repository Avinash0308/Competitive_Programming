#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int x)
    {
        // code here
        vector<int> v;
        int i = 0;
        int max = 0;
        int res = 0;
        int zero = 0;
        int start = 0;
        while (i < n)
        {
            if (arr[i] == 1)
            {
                res++;
            }
            else
            {
                v.push_back(i);
                if (x)
                {
                    res++;
                    x--;
                }
                else
                {
                    res -= (v[zero] - start);
                    start = v[zero] + 1;
                    zero++;
                }
            }
            if (res > max)
            {
                max = res;
            }
            i++;
        }
        return max;
    }
};
int main()
{
    // //Different And Mine One of the Best Code on GFG
    return 0;
}