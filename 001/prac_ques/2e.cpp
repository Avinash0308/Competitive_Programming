#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int ans = 0;
        int given_no;
        cin >> given_no;
        if (given_no == 1 || given_no == 2)
        {
            cout << "1" << endl;
        }
        if (given_no == 3)
        {
            cout << "2" << endl;
        }
        else
        {

            for (int y = 4; y <= sqrt(given_no); y++)
            {
                int bits_of_y;
                bits_of_y = (int)log2(y) + 1;
                int x = given_no / y;

                int bits_of_x = (int)log2(x) + 1;
                if (bits_of_x <= bits_of_y)
                {
                    ans = given_no - y + 1;
                    goto end;
                }
            }
        }
    end:
        cout << ans << endl;
    }
    // Reading input from STDIN

    // Writing output to STDOUT
    return 0;
}