#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<long long int> v;
        long long int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin() , v.end());
        long long int x = v[0];
        for(int i = 1 ; i<n ; i++){
            x = __gcd(x , v[i]);
        }
        cout<<x*n<<endl;
    }
    return 0;
}
