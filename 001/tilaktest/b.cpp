#include<bits/stdc++.h>
using namespace std;



int main(){
    map<int,int> mp;
    mp[5] = 1;
    mp[4] = 10;
    auto x = mp.find(5);
    x--;
    cout<<x->first<<endl;
    return 0;
}