#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, r;
        cin >> a >> b >> r;
        if (r == 0)
            cout << abs(a - b) << endl;
        else if (a == b)
            cout << 0 << endl;
        else
        {
            if (a < b)
                swap(a, b);
            int xor_ab = a ^ b;
            int msb = 1 << (int)log2(xor_ab); // Finding the position of the most significant bit in xor_ab

            // If r is less than the most significant bit position, then x can't exceed r
            if (r < msb)
            {
                cout<< min(abs(a - b), abs((a ^ r) - (b ^ r)))<<endl;
            }

            // Otherwise, x can be chosen such that it flips only the differing bits
            else cout<< xor_ab<<endl;
        }
    }
    return 0;
}