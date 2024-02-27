#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int  test_cases;
    cin >> test_cases;
    while(test_cases--)
    {
        int ans = 0;
        int  given_no;
        cin >> given_no;

        for (int  y = 1; y <= given_no; y++)
        {
            int bits_of_y;
            int b = 0;
            int j;
            j =y;
            while (j)
            {
                b++;
                j/=2;
            }
            bits_of_y = b;
            int  x = given_no / y;
            j = x;
            b = 0;
            while (j)
            {
                b++;
                j/=2;
            }
            int bits_of_x = b;
            if(bits_of_x<=bits_of_y){
                ans = given_no - y + 1;
                goto end;
            }
        }
        end:
        cout << ans << endl;
    }
    // Reading input from STDIN

    // Writing output to STDOUT
    return 0;
}