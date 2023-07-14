#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long a = 0;
        long long ar[N];
        copy(arr, arr + N, ar);
        long long min = *min_element(arr, arr + N);
        long long max = *max_element(arr, arr + N);
        for (long long i = 0; i < N / 2; i++)
        {
            vector<int>::iterator it;
            // it = find(ar, ar + N, arr[i]);

            for (long long j = i + 1; j < N; j++)
            {

                if (arr[i] > arr[j])
                {
                    a++;
                }
            }
        }
        return a;
    }
};
int main()
{

    return 0;
}