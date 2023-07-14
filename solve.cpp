#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<vector<int>> v(3);
    for(int i = 0; i<n; i++){
        v[A[i]%3].push_back(A[i]);
    }
    long long int sum = 0;
    long long mul = 1;
    for(int i = 0; i<3; i++){
        for(int x = 0; x<32 ;x++){
            mul*=(x+1);
            int bit_sum = 0;
            int odd= 0, even = 0;
            for(int j = 0; j<v[i].size(); j++){
                if(v[i][j]%2){
                    odd++;
                }
                else{
                    even++;
                }
                v[i][j]/=2;
            }
            sum += (odd*even*mul);
        }
    }
    return sum;
}