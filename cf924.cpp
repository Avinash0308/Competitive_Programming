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
        if(n <= 28){
            char w = char(n-2 + 96);
            cout<<"aa"<<w<<endl;
        }
        else if(n >= 53){
            char w = char(n-53 +97);
            cout<<w<<"zz"<<endl;
        }
        else{
            char w = char(n-28+97);
            cout<<"a"<<w<<"z"<<endl;
        }
    }
    return 0;
}