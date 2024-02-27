#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string convert(string s)
{
    // code here.
    string ss;
    for(int i = 0; i<s.length() ;i++){
        if((int)s[i] > 64 && (int)s[i] <91){
            ss+=(char)(155-(int)s[i]);
        }
        if((int)s[i] >96 && (int)s[i]<123){
            ss+=(char(219-(int)s[i]));
        }
    }
    return ss;
}
int main(){
    
return 0;
}