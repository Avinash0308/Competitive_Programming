// Program to convert Roman
// Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

int value(char r)
{
    if (r == 'A')
        return 1;
    if (r == 'B')
        return 10;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 1000;
    if (r == 'E')
        return 10000;

    return -1;
}

long long int roman(string &str){
    long long int cur = 0, val = 0;
    int n = str.size();
    for(int i = 0; i<n; i++){
        int x = value(str[i]);
        if(cur >= x){
            val += x;
        }
        else{
            cur = x;
            val = x - val;
        }
    }
    return val;
}

long long int solve(string &s){
    long long int cur = roman(s);
    vector<vector<int>> v(n)
    
}

int main()
{
    string str = "ABACAE";
    cout<<roman(str)<<endl;

    return 0;
}
