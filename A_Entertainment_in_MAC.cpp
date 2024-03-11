#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string r = s;
        reverse(s.begin(),s.end());
        string t = r;
        r = s;
        s = t;
        if(s>r){
            r += s;
            s = r;
        }
        cout<<s<<endl;
    }
    return 0;
}