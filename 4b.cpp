#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solveit(unsigned long long int n)
{
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

    unsigned long long int a = 1;
    int i = 0;
    while (a <= n && i < 16)
    {
        a *= arr[i];
        i++;
    }
    cout << i-1 << endl;
}
int main()
{
    long int test, i;
    cin >> test;
    unsigned long long int n;
    for (i = 0; i < test; i++)
    {
        cin >> n;
        solveit(n);
    }
    return 0;
}