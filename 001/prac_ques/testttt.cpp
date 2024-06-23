#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<pair<int,int>, greater<pair<int,int>> > p;
    p.insert({2,1});
    p.insert({2,2});
    for(auto i:p){
        cout<<i.second<<endl;
    }
return 0;
}