#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string create(long long int a, long long int b)
{
    stringstream ss;
    ss << a;
    string s;
    ss >> s;
    s += " ";
    stringstream sss;
    sss << b;
    string str2;
    sss >> str2;
    s += str2;
    return s;
}
int main(){
    string s = create(20,26);
    cout<<s<<endl;
    cout<<s.size()<<endl;
return 0;
}