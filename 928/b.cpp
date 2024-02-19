#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c;
                cin >> c;
                if (c == '1')
                    v[i]++;
            }
        }   
        int ind = 0;
        while(ind<n && v[ind] == 0) ind++;
        if(v[ind+1] == v[ind]){
            cout<<"SQUARE"<<endl;
        }
        else{
            cout<<"TRIANGLE"<<endl;
        }
    }
    return 0;
}