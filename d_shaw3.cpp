#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> A, vector<int> z){
    int n = A.size(), m = A[0].size();
    vector<int> v(n);
    int maxy = 0;
    int val1 = 1;
    for(int i= 0; i<m; i++){
        maxy += val1;
        val1*=2;
    }
    for(int i = 0; i<n; i++){
        int cur = 1;
        int val = 0;
        for(int j = m-1; j>=0; j--){
            if(A[i][j] >= z[j]){
                val += cur;
            }
            cur*=2;
        }
        v[i] = val;
    }
    int count = 0;
    for(int i = 0; i<n;i ++){
        if(v[i] == maxy){
            count += ((n-i-1)*2 + 1);
            continue;
        }
        for(int j = i+1; j<n; j++){
            if((v[i]|v[j]) == maxy) count+=2;
        }
    }
    return count;
}
int main(){
    cout<<solve({{1,1,7,8},{6,6,7,8}},{2,2,6,6})<<endl;
}