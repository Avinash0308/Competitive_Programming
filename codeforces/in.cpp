#include<bits/stdc++.h>
using namespace std;



int main(){
    vector<int> v;
    string s;
    int data;
    while(getline(cin,s) != ""){
        data = stoi(s);
        v.push_back(data);
    }
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}