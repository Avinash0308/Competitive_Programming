#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    vector<vector<int>> query(q,vector<int>(3));
    for(int i = 0; i<q; i++){
        for(int j = 0; j<3 ;j++){
            cin>>query[i][j];
        }
    }
    vector<int> left(n,0), right(n,n-1);
    stack<pair<int,int>> s;
    for(int i = 0; i<n; i++){
        while(!s.empty() && s.top().first < a[i]){
            int ind = s.top().second;
            right[ind] = i-1;
            s.pop();
        }
        s.push({a[i],i});
    }
    while(!s.empty()) s.pop();
    for(int i = n-1; i>=0; i--){
        while(!s.empty() && s.top().first < a[i]){
            int ind = s.top().second;
            left[ind] = i+1;
            s.pop();
        }
        s.push({a[i],i});
    }
    vector<unordered_map<int,int>> count(n);
    unordered_map<int,int> um;
    for(int i = 0; i<n; i++){
        um[a[i]]++;
        count[i]= um;
    }
    
return 0;
}