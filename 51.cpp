#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n)
    {
        // code here
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long x = arr[i] * arr[i] + arr[j] * arr[j];
                for (int k = j + 1; k < n; k++)
                {
                    long long y = arr[k] * arr[k];
                    if (x == y)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    int arr[] = {25, 4, 5, 24, 7, 9};
    if (s.checkTriplet(arr, 6))
    {
        cout << "Ho gaya kaam" << endl;
    }
    else
    {
        cout << "Tumse na ho payega" << endl;
    }
    return 0;
}