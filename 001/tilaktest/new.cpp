#include<bits/stdc++.h>
using namespace std;



int main(){
    int n, b, c;
    cin>>n>>b>>c;
    vector<int> v(n);
    for(int i = 0;i<n; i++){
        cin>>v[i];
    }
    int ans = 0;
    for(int i= 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += v[j];
            if(sum >= b && sum <= c) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}