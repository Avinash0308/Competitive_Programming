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
    int m;
    cin>>m;
    vector<vector<int>> query(q,vector<int>(m));
    for(int i = 0; i<q; i++){
        for(int j = 0; j<m ;j++){
            cin>>query[i][j];
        }
    }
    vector<unordered_map<int,int>> count(n);
    unordered_map<int,int> um;
    for(int i = 0; i<n; i++){
        um[a[i]]++;
        count[i]= um;
    }
    long long int ans = 0;
    long long int mod = 1e9 + 7;
    for(int i = 0; i<q; i++){
        long long int cur = 0;
        int l = query[i][0]-1, r = query[i][1]-1, x = query[i][2];
        for(int z = l; z<=r; z++){
            int maxy = 0;
            for(int y = z; y<=r; y++){
                maxy = max(maxy,a[y]);
                if(maxy == x){
                    long long int occ_z, occ_y;
                    if(z == 0) occ_z = 0;
                    else occ_z = count[z-1].count(x);
                    occ_y = count[y].count(x);
                    cur = max(cur,occ_y-occ_z);
                }
            }
        }
        ans = (ans+cur)%mod;
    }
    cout<<ans<<endl;
return 0;
}