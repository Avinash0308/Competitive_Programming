#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(string a, string b)
{
    int n = a.size(), m = b.size(), i = 0, j = 0;
    while(i<n && j<m){
        if(a[i] == b[j]){
            i++;
            j++;
        }
        else{i++;}
    }
    return j;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string b;
        cin >> b;
        int n = a.size(), m = b.size();
        int ans = 0;
        for(int i = 0; i<m; i++){
            string cur = b.substr(i,m-i);
            while(ans < cur.size()){
                int val = solve(a,cur);
                ans = max(ans,val);
                cur.pop_back();
            }
        }
        cout << n+m-ans << endl;
    }
    return 0;
}