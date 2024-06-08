#include<bits/stdc++.h>
using namespace std;

vector<int> getMaxElementIndexes(vector<int> &a, vector<int> &rotate){
    int n = a.size(), m = rotate.size();
    vector<int> ans(m);
    int maxy = -1, ind = -1;
    for(int i = 0; i<n; i++){
        if(maxy < a[i]) {maxy = a[i],ind = i;}
    }
    for(int i = 0 ;i<m; i++){
        int r = rotate[i]%n;
        if(ind >= r) ans[i] = ind-r;
        else{
            r -= ind;
            ans[i] = n-r;
        }
    }
    return ans;
}

int main(){
    vector<int> a = {1,2,4,3};
    vector<int> ro = {0,2};
    vector<int> ans = getMaxElementIndexes(a,ro);
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}   