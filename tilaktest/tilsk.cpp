#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, b, c;
    cin>>n>>b>>c;
    vector<int> v(n);
    for(int i = 0;i<n; i++){
        cin>>v[i];
    }
    int ans = 0, start = 0, cur = 0;
    for(int i= 0; i<n; i++){
        cur += v[i];
        if(cur < b) continue;
        if(cur >= b && cur <= c){
            
        }
    }
    cout<<ans<<endl;
    return 0;
}