#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &nums, int k, int n)
    {

        // c will be storing Bitwise AND of supermasks of K.
        int res_and = INT_MAX;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & k == k)
            {
                res_and = res_and & nums[i];
                count++;
            }
        }

        // check whether the AND obtained is equal or not to k.
        if (res_and == k && count > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool check_bit_and(vector<int> &nums, int k)
    {
        int n = nums.size();
        bool ans = solve(nums, k, n);
        return ans;
    }
};
