#include <bits/stdc++.h>
using namespace std;

int solve(string A) {
    string rev = A;
    reverse(A.begin(),A.end());
    int n = A.size();
    vector<int> lps(n+1);
    int i = 1, len = 0;
    while(i<=n){
        if(A[i-1] == rev[len]){ 
            lps[i++] = ++len;
        }
        else if(len > 0){
            len = lps[len-1];
        }
        else i++;
    }
    return n - lps[n];
}


int main()
{
    string a = "babb";
    cout<<solve(a)<<endl;
    return 0;
}