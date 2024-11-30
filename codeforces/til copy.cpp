#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> tree){
    vector<vector<int>> v(n,vector<int>(n,0));
    int maxy = INT_MIN, x, y;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            v[i][j] = abs(tree[i][0]-tree[j][0]) + abs(tree[i][1]-tree[j][1]);
            v[j][i] = v[i][j];
            if(maxy < v[j][i]){
                x = j, y = i;
                maxy = v[j][i];
            }
        }
    }
    int a = 0, b = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(i != x && j != x) a = max(a,v[i][j]);
            if(i != y && j != y) b = max(b,v[i][j]);
        }
    }
    return min(a,b);
}

int main(){
    vector<vector<int>> v = {{1,2},{2,4},{2,6},{3,9},{2,8}};
    cout<<solve(5,v)<<endl;
    return 0;
}