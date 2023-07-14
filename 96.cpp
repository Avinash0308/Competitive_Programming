#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(9);
    int a = 1;
    for(int i = 0; i<9; i++){
        a *= (i+1);
        v[i] = a;
    }
    for(int i = 0; i<9; i++){
        cout<<v[i]<<" ";
    }
return 0;
}