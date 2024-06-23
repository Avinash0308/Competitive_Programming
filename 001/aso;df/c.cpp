#include <bits/stdc++.h>
using namespace std;

// Returns length of the longest prefix
// which is also suffix and the two do
// not overlap. This function mainly is
// copy computeLPSArray() of in below post
// https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
int longestPrefixSuffix(string str)
{
    int ans = 0;
    vector<int> A(str.size(), 0);
    int j = 0, i = 1;

    // Loop to calculate the prefix array
    while (i < str.size())
    {
        if (str[i] == str[j])
        {
            // Increment j by 1 and assign the value to the prefix array
            A[i] = j + 1;
            ans = max(ans,A[i]);
            j++;
            i++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                // Set j to the previous value in the prefix array
                j = A[j - 1];
        }
    }

    // Return the last element of the prefix array
    return ans;
}

// Driver program to test above function
int main()
{
    string s = "abadabab";
    cout << longestPrefixSuffix(s);
    return 0;
}