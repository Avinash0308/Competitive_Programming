// C++ implementation to count the
// number of ways to divide N in
// groups such that each group
// has K number of elements

#include <bits/stdc++.h>

using namespace std;

// Function to count the number
// of ways to divide the number N
// in groups such that each group
// has K number of elements
int calculate(int pos, int prev,
              int left, int k)
{
    // Base Case
    if (pos == k)
    {
        if (left == 0)
            return 1;
        else
            return 0;
    }

    // if N is divides completely
    // into less than k groups
    if (left == 0)
        return 0;

    int answer = 0;

    // put all possible values
    // greater equal to prev
    for (int i = prev; i <= left; i++)
    {
        answer += calculate(pos + 1, i,
                            left - i, k);
    }
    return answer;
}

// Function to count the number of
// ways to divide the number N
int countWaystoDivide(int n, int k)
{
    return calculate(0, 1, n, k);
}

// Driver Code
int main()
{
    int N = 8;
    int K = 4;

    cout << countWaystoDivide(9, 5);
    return 0;
}