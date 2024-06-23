#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long long int ver, sou, sinks;
        cin >> ver >> sou >> sinks;
        long long int z = 0;
        if (sou + sinks <= ver)
        {
            z = sou * (ver - sou) + sinks * (ver - sou - sinks) + ((ver - sou - sinks) * (ver - sou - sinks - 1)) / 2;
        }
        else
        {
            int a = sou + sinks - ver;
            sou -= a;
            sinks -= a;
            z = sou * sinks;
        }
        cout << z << endl;
    }
    return 0;
}