#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    int n;
    cin>>n;
    int q;
    cin>>q;
    int m;
    cin>>m;
    vector<int> v(n);
    for(int i= 0; i<n; i++){
        cin>>v[i];
    }
    for(int i = 0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 1){
            v[b-1] = (v[b-1]+1)%2;
        }
        else{
            int low = b-1, high = c-1;
            while(low<=high && v[low] == 0)low++;
            while(high >= low && v[high] == 1) high--;
            int one = 0, zero = 0;
            while(low<=high){
                if(v[low]) one++;
                else zero++;
                low++;
            }
            ans += min(zero,one);
        }
    } 
    return ans;
}

long solve(int n, int q, int m, vector<int> v, vector<vector<int>> query){
    int ans =  0;
    for(int i = 0; i<q; i++){
        int a, b, c;
        a = query[i][0], b = query[i][1], c= query[i][2];
        if(a == 1){
            v[b-1] = (v[b-1]+1)%2;
        }
        else{
            int low = b-1, high = c-1;
            while(low<=high && v[low] == 0)low++;
            while(high >= low && v[high] == 1) high--;
            int one = 0, zero = 0;
            while(low<=high){
                if(v[low]) one++;
                else zero++;
                low++;
            }
            ans += min(zero,one);
        }
    } 
    return ans;
}