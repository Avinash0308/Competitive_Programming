#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
        // Your code goes here
        int max = *max_element(arr2, arr2 + n);
        int min = *min_element(arr2, arr2 + n);
        int max2 = *max_element(arr1, arr1 + m);
        int min2 = *min_element(arr1, arr1 + m);
        vector<int> avi(100000, 0);
        sort(arr2, arr2 + n);
        int x = 0;

        if (arr2[n / 2] <= min2)
        {
            int j = n / 2;
            while (arr2[j] <= min2)
            {
                j++;
            }
            x = j;
        }
        else if (arr2[n / 2] > min2)
        {
            int j = n / 2;
            while (arr2[j] > min2)
            {
                j--;
            }
            x = j + 1;
        }

        vector<int> v(m, x);
        for (int i = 0; i < m; i++)
        {
            int as = x;
            if (max <= arr1[i])
            {
                as = n;
            }
            else if (min > arr1[i])
            {
                as = 0;
            }
            else
            {
                int j = as - 1;
                while (j < n && arr2[j] <= arr1[i])
                {
                    j++;
                }
                as = j;
            }
            v[i] = as;
        }
        return v;
    }
};
int main()
{

    return 0;
}