#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<string> a, vector<int> b){
    int n = a.size();
    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        int open = 0, count = 0;
        for(auto c:a[i]){
            if(c == '<') open++;
            else{
                if(open) open--;
                else count++;
            }
        }
        if(open || count > b[i]) ans[i] = 0;
        else ans[i] = 1;
    }
    return ans;
}

int main(){
    return 0;
}