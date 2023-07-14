#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    long long int t;
    cin >> t;
    while (t--)
    {
        int x, y, z, n = 0, n2 = 0, n1 = 0, n3 = 0;
        cin >> x >> y >> z;
        if (x == 0)
        {
            n++;
        }
        if (y == 0)
        {
            n++;
        }
        if (z == 0)
        {
            n++;
        }
        if (x >= 2)
        {
            n2++;
        }
        if (y >= 2)
        {
            n2++;
        }
        if (z >= 2)
        {
            n2++;
        }
        if (x == 1)
        {
            n1++;
        }
        if (y == 1)
        {
            n1++;
        }
        if (z == 1)
        {
            n1++;
        }
        if (x >= 3)
        {
            n3++;
        }
        if (y >= 3)
        {
            n3++;
        }
        if (z >= 3)
        {
            n3++;
        }
        if (n == 3)
        {
            cout << "0" << endl;
            goto end;
        }
        else if (n == 2)
        {
            cout << "1" << endl;
            goto end;
        }
        else if (n == 1)
        {
            if (n2 == 2)
            {
                cout << "3" << endl;
                goto end;
            }
            if (n2 == 1 || n2 == 0)
            {
                cout << "2" << endl;
                goto end;
            }
        }
        else
        {
            if (n3 == 3)
            {
                cout << "6" << endl;
                goto end;
            }
            if (n3 == 2)
            {
                if (n2 == 3)
                {
                    cout << "5" << endl;
                    goto end;
                }
                if (n2 == 2)
                {
                    cout << "4" << endl;
                    goto end;
                }
            }
            if (n3 == 1)
            {
                if (n2 == 3)
                {
                    cout << "5" << endl;
                    goto end;
                }
                if (n2 == 2)
                {
                    cout << "4" << endl;
                    goto end;
                }
                if (n2 == 1)
                {
                    cout << "3" << endl;
                    goto end;
                }
            }
            else
            {
                if (n1 == 3 || n1 == 2)
                {
                    cout << "3" << endl;
                    goto end;
                }
                if (n1 == 1 || n1 == 0)
                {
                    cout << "4" << endl;
                    goto end;
                }
            }
        }
    end:
        continue;
    }
    return 0;
}
