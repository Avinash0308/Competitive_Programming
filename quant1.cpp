#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long solution(int N, vector<vector<int>> &patient){
    long long ans = 0;
    long long cur = 0;
    for(int i = 0; i<N; i++){
        if(cur < patient[i][0]) cur = patient[i][0];
        else{
            ans += cur-patient[i][0];
        }
        cur += patient[i][1];
        ans += patient[i][1];
    }
    return ans/N;
}

int main(){
    vector<vector<int>> test = {{5,2},{5,4},{10,3},{20,1}};
    cout<<solution(4,test)<<endl;
return 0;
}