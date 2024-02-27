#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        vector<vector<int>> v;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            vector<int> x(m, -1);
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    x[j] = 0;
                }
                else
                {
                    if (i == 0)
                    {
                        if (j == 0)
                        {
                            if ((grid[i + 1][j] && i < n - 1) || (grid[i][j + 1] && j < m - 1))
                            {
                                x[j] = 1;
                            }
                        }
                        else if (j == m - 1)
                        {
                            if ((grid[i + 1][j] && i < n - 1) || (grid[i][j - 1] && j > 0))
                            {
                                x[j] = 1;
                            }
                        }
                        else
                        {
                            if ((grid[i + 1][j] && i < n - 1) || (grid[i][j - 1] && j > 0) || (grid[i][j + 1] && j < m - 1))
                            {
                                x[j] = 1;
                            }
                        }
                    }
                    else if (i == n - 1)
                    {
                        if (j == 0)
                        {
                            if ((grid[i - 1][j] && i > 0) || (grid[i][j + 1] && j < m - 1))
                            {
                                x[j] = 1;
                            }
                        }
                        else if (j == m - 1)
                        {
                            if ((grid[i - 1][j] && i > 0) || (grid[i][j - 1] && j > 0))
                            {
                                x[j] = 1;
                            }
                        }
                        else
                        {
                            if ((grid[i - 1][j] && i > 0) || (grid[i][j - 1] && j > 0) || (grid[i][j + 1] && j < m - 1))
                            {
                                x[j] = 1;
                            }
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            if ((grid[i - 1][j]) || (grid[i + 1][j]) || (grid[i][j + 1] && j < m - 1))
                            {
                                x[j] = 1;
                            }
                        }
                        else if (j == m - 1)
                        {
                            if ((grid[i][j - 1] && j > 0) || (grid[i - 1][j] && i > 0) || (grid[i + 1][j] && i < n - 1))
                            {
                                x[j] = 1;
                            }
                        }
                        else
                        {
                            if ((grid[i][j - 1] && j > 0) || (grid[i][j + 1] && j < m - 1) || (grid[i + 1][j] && i < n - 1) || (grid[i - 1][j] && i > 0))
                            {
                                x[j] = 1;
                            }
                        }
                    }
                }
                if (x[j] == -1)
                {
                    if (i == 0)
                    {
                        if (j > 0)
                        {
                            if (x[j - 1] != -1)
                            {
                                x[j] = x[j - 1] + 1;
                            }
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            if (v[i - 1][j] != -1)
                            {
                                x[j] = v[i - 1][j] + 1;
                            }
                        }
                        else
                        {
                            if (v[i - 1][j] != -1 && x[j - 1] != -1)
                            {
                                x[j] = min(v[i - 1][j], x[j - 1]) + 1;
                            }
                            else if (v[i - 1][j] != -1)
                            {
                                x[j] = v[i - 1][j] + 1;
                            }
                            else if (x[j - 1] != -1)
                            {
                                x[j] = x[j - 1] + 1;
                            }
                        }
                    }
                }
            }
            v.push_back(x);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1)
                {
                    if (j < m - 1)
                    {
                        if (v[i][j] == -1)
                        {
                            v[i][j] = v[i][j + 1] + 1;
                        }
                        else
                        {
                            v[i][j] = min(v[i][j], v[i][j + 1] + 1);
                        }
                    }
                }
                else
                {
                    if (j == m - 1)
                    {
                        if (v[i][j] == -1)
                        {
                            v[i][j] = v[i + 1][j] + 1;
                        }
                        else
                        {
                            v[i][j] = min(v[i][j], v[i + 1][j] + 1);
                        }
                    }
                    else
                    {
                        if (v[i][j] == -1)
                        {
                            v[i][j] = min(v[i][j + 1], v[i + 1][j]) + 1;
                        }
                        else
                        {
                            v[i][j] = min(v[i][j], (min(v[i + 1][j], v[i][j + 1]) + 1));
                        }
                    }
                }
            }
        }
        return v;
    }
};
int main()
{

    return 0;
}