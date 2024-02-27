#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
        // Your code here
        sort(arr, arr + n);
            int a = 0;
        for (int i = 0; i < n; i++)
        {
            a = arr[i];
            if (a <= 0)
            {

                for (int j = i + 1; j < n; j++)
                {
                    a = arr[i] + arr[j];
                    if (a <= 0)
                    {

                        for (int k = j + 1; k < n; k++)
                        {
                            a = arr[i]  + arr[j] + arr[k];
                            if (a <= 0)
                            {
                                if(a==0){
                                    return 1;
                                }
                            }
                            else{
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            else
            {
                return 0;
            }
        }
    }
};
int main()
{

    return 0;
}