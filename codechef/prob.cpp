#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; // n - rows, m - columns
    cin >> n >> m;
    char arr[n][m]; // 2d array of char of dimension n*m
    for (int i = 0; i < n; i++)
    { // iteratring from 0th row to n-1 th row
        for (int j = 0; j < m; j++)
        { // iterating from 0th to m-1 index of each row
            cin >> arr[i][j];
        }
    }
    int x, y; // x and y co-ordinates of given cell
    cin >> x >> y;
    x--; // chaging 1-based indexing to 0-based.
    y--;
    //int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; // storing all 8 directions
    int dir[9] = {1,0,-1,0,1,-1,-1,1,1};
    bool possible = true;                                                                   // to check if all 8 direction store 'x'
    for (int i = 0; i < 8; i++)
    {                                             // checking all 8 direction
        int a = x + dir[i], b = y + dir[i+1]; // updating x & y co-ordinates
        if (a >= 0 && a < n && b >= 0 && b < m && arr[a][b] == '.')
        { // if a & b, both are inside matrix and contain '.' then answer is no, so update value of possible to false
            possible = false;
            break;
        }
    }
    if (possible)
        cout << "yes" << endl; // if possible is true, means all eight cells either contain 'x' or are out of matrix, if cell is out of matrix we need to conisder it as 'x'
    else
        cout << "no" << endl; // else print no
    return 0;
}