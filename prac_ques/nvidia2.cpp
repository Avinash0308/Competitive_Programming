#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solve(string &a){
    if(!a.size()) return false;
    if(a[0] != '1') return false;
    for(int i = 1; i<a.size(); i++){
        if(a[i] != '0') return false;
    }
    return true;
}
int main(){
    string a;
    cout<<solve(a)<<endl;
return 0;
}