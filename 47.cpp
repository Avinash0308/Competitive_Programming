#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        // code here
        for (int i = 0; i < n; i += k)
        {
            if (i + k <= n)
            {
                for (int j = 0; j < k / 2; j++)
                {
                    int temp = arr[i + k - 1 - j];
                    arr[i + k - 1 - j] = arr[j + i];
                    arr[j + i] = temp;
                }
            }
            else
            {
                for (int j = 0; j < (n - i) / 2; j++)
                {
                    int temp = arr[n - 1 - j];
                    arr[n - 1 - j] = arr[j + i];
                    arr[j + i] = temp;
                }
            }
        }
    }
};
int main()
{

    return 0;
}