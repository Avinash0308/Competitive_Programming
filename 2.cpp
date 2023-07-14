#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int  test_cases;
    cin >> test_cases;
    for (int  i = 0; i < test_cases; i++)
    {
        int ans = 0;
        int  given_no;
        cin >> given_no;

        for (int  y = 1; y <= given_no; y++)
        {
            int bits_of_y;
            int b = 1;
            int j = 0;
            while (b)
            {
                if ((y >= pow(2, j)) && (y < pow(2, j + 1)))
                {
                    bits_of_y = j + 1;
                    b = 0;
                }
                j++;
            }
            int  x = given_no / y;
            j = 0;
            b = 1;
            while (b)
            {
                if ((x >= pow(2, j)) && (x < pow(2, j + 1)))
                {
                    int bits_of_x = j + 1;
                    if (bits_of_x <= bits_of_y)
                    {
                        ans = given_no + 1 - y;
                        goto end;
                    }
                    b = 0;
                }
                j++;
            }
        }
        end:
        cout << ans << endl;
    }
    // Reading input from STDIN

    // Writing output to STDOUT
    return 0;
}