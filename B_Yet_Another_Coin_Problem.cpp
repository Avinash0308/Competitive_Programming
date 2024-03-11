#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<long long int> ans(5);
        vector<int> v = {0,1,2,1,2,3,1,2,3,2,1,2,2,2,3};
        vector<int> val = {1,3,6,10,15};
        long long int res = INT_MAX;
        for(int i = 0; i<5; i++){
            long long int ans = n/val[i];
            long long int rem = n%val[i];
            if((val[i] == 15 && n>=23 && rem == 8)){
                ans += 2;
            }
            else if((val[i] == 15 && n>=20 && rem == 5))ans+=1;
            else{
                ans += v[rem];
            }
            res = min(res,ans);
        }
        cout<<res<<endl;
    }
return 0;
}