#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function to get all
    // possible subsequences for given array
    void getSubsequence(vector<int> &nums, int ind, vector<int> &arr, int n, bool &check, int &k)
    {

        // Check the subsequence when reach
        // the leaf of recursion tree
        if (ind == n)
        {

            if (arr.size() != 0)
            {
                int bit_and = arr[0];

                for (int i = 1; i < n; i++)
                {
                    bit_and &= arr[i];
                }

                if (bit_and == k)
                {
                    check = true;
                }
            }

            return;
        }
        else
        {

            // pick the current index into the subsequence.
            arr.push_back(nums[ind]);

            if (check == false)
                getSubsequence(nums, ind + 1, arr, n, check, k);

            arr.pop_back();

            // not picking the element into the subsequence.
            if (check == false)
                getSubsequence(nums, ind + 1, arr, n, check, k);
        }
    }

    bool check_bit_and(vector<int> &nums, int k)
    {
        bool check = false;
        int n = nums.size();
        vector<int> arr;
        getSubsequence(nums, 0, arr, n, check, k);
        return check;
    }
};
