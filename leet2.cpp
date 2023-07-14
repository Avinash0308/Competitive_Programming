#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &nums, int k, int n)
    {

        // generate the binary form of given value k
        //  using an array of size 32 because as per constraints
        //  the max value will be 2^30
        vector<int> k_bits(32);
        int ind = 0;
        while (k)
        {
            k_bits[ind] = k % 2;
            k /= 2;
            ind++;
        }

        // similarly generate the binary form of each element of given array.
        vector<vector<int>> n_bit(n, vector<int>(32, 0));
        for (int i = 0; i < n; i++)
        {
            ind = 0;
            while (nums[i])
            {
                n_bit[i][ind] = nums[i] % 2;
                nums[i] /= 2;
                ind++;
            }
        }

        // create an array to check whether we can use current element of array or not.
        vector<int> can_visit(n, 1);

        // Bitwise AND of set and unset bit is unset, so if any bit of k is set, then we need to remove all those element from array whose current bit is unset.
        for (int i = 0; i < 32; i++)
        {
            if (k_bits[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (can_visit[j] == 1 && n_bit[j][i] == 0)
                    {
                        can_visit[j] = 0;
                    }
                }
            }
        }

        // Now for unset bit of k, we need to ensure that there exist atleast single element in array whose similar bit is unset
        for (int i = 0; i < 32; i++)
        {
            if (k_bits[i] == 0)
            {
                bool found = false;
                for (int j = 0; j < n; j++)
                {
                    if (can_visit[j] && n_bit[j][i] == 0)
                    {
                        found = true;
                        break;
                    }
                }
                if (found == false)
                {
                    return false;
                }
            }
        }

        // now after all the operations, check whether there
        //  exist atleast a single element of array which
        //  can be used to generate the value k
        for (int i = 0; i < n; i++)
        {
            if (can_visit[i] == 1)
            {
                return true;
            }
        }
        return false;
    }

    bool check_bit_and(vector<int> &nums, int k)
    {
        int n = nums.size();
        bool ans = solve(nums, k, n);
        return ans;
    }
};
