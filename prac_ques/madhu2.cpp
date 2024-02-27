#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix;                  // input your matrix here.
    int n = matrix.size(), m = matrix[0].size(); // matrix.size() is no of rows in a matrix and matrix[0].size() refers to size of columns in matrix;
    int max = 0, ind = 0;                        // max will store the max sum of all rows and ind will store the index of row with max sum.
    for (int i = 0; i < n; i++)
    {
        int sum = 0; // sum will store the sum of current row i.e. row no. i;
        for (int j = 0; j < m; j++)
        {
            sum += matrix[i][j];
        }
        if (sum > max)
        {              // if sum of element of current row is greater than max value
            max = sum; // store the value of sum in max
            ind = i;   // and update the index of max sum row.
        }
    }
    cout << "The Row with maximum sum is: " << ind << endl;
    return 0;
}