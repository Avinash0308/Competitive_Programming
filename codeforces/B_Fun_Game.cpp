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
        cin >> n;
        string s;
        cin >> s;
        string t;
        cin >> t;
        if (s == t)
            cout << "YES" << endl;
        else
        {
            if (s[0] == '0' && t[0] == '1')
                cout << "NO" << endl;
            else
            {
                if (s[0] == '1')
                    cout << "YES" << endl;
                else
                {
                    int loc = -1;
                    for (int i = 0; i < n; i++)
                    {
                        if (s[i] == '1')
                        {
                            loc = i;
                            break;
                        }
                    }
                    if (loc == -1)
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        int x  = 0;
                        for(int i = 0; i<loc; i++){
                            if(s[i] != t[i]){
                                cout<<"NO"<<endl;
                                x = 1;
                                break;
                            }
                        }
                        if(!x) cout<<"YES"<<endl;
                    }
                }
            }
        }
    }
    return 0;
}