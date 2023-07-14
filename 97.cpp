#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> queries;
    int n ;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<queries.size(); i++){
        a[queries[i][0] - 1] += queries[i][2];
        b[queries[i][1] - 1] += queries[i][2];;
    }
    int cur = 0 , maxy = 0;
    for(int i = 0; i<n ; i++){
        cur += a[i];
        maxy = max(maxy,cur);
        cur -= b[i];
    }
    return maxy;
}