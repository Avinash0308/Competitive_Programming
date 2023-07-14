#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,pair<int,string>> m;
    m[509] = {12266,"Starters 49"};
    m[579] = {13194,"August Lunchtime 2022"};
    m[135] = {3930,"September Long 2022"};
    m[832] = {3540,"Starters 56"};
    m[896] = {2873,"Starters 59"}; 
    m[231] = {3086,"October Long 2022"};
    m[384] = {3319,"Starters 64"};
    m[81] = {15931,"Starters 67"};
    m[125] = {14293,"Starters 68"};
    m[58] = {2297,"December Long 2022"};
    m[362] = {3892,"Starters 70"};
    m[247] = {3721,"Starters 72"};
    m[302] = {1000,"Starters 76"};
    for(auto i : m){
        cout<<"Rank : "<<i.first<<endl<<"Participants : "<<i.second.first<<endl<<"contest : "<<i.second.second<<endl<<endl;
    }
    return 0;
}