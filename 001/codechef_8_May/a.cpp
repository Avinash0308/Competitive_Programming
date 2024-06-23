#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    vector<int> v = {1,2,3};
    int ind = upper_bound(v.begin(),v.end(),3)-v.begin();
    cout<<ind<<endl;
    return 0;
}