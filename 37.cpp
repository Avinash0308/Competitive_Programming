#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reciprocalString(string s)
    {
        string ss;
    for(int i = 0; i<s.length() ;i++){
        if((int)s[i] > 64 && (int)s[i] <91){
            ss+=(char)(155-(int)s[i]);
        }
        if((int)s[i] >96 && (int)s[i]<123){
            ss+=(char)(219-(int)s[i]);
        }
        else if((int)s[i] >122 || (int)s[i]<65 ||( (int)s[i]>90 && (int)s[i]<97)){
            ss+=s[i];
        }
    }
    return ss;
    }
};
int main(){ 
    
return 0;
}