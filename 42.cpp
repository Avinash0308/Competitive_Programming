#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int a;
        cin >> a;
        vector<int> v;
        for (int i = 0; i < a; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int x=0;
        for (int i = 0; i < a-1; i+=2)
        {
            if (v[i] == v[i + 1])
            {
                while (v[i] == v[i + 1])
                {
                    i++;
                    x++;
                }
                swap(v[i], v[i + 1]);
            }
        }
        if(v[0] == v[a-1] && a%2 == 0){
            x++;
        }
        if(x%2 == 0){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
    }
    // your code goes here
    return 0;
}
