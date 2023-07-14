#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v ;
    v.push_back(34);
    v.push_back(3);
    v.push_back(4);
    vector<int> x;
    x.push_back(2);
    x.push_back(21);
    x.push_back(24);
    x = v;
    for(int i = 0; i<x.size() ; i++){
        cout<<x[i]<<endl;
    }
return 0;
}