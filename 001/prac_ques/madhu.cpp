#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    int max = a[0][0];
    int i, j, x = 0, y = 0;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << "Max Element: " << max << endl;
    cout << "Index: " << x << " " << y << endl;
    return 0;
}