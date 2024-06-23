#include<bits/stdc++.h>
using namespace std;
int main (){
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<int>a;
        for(int i = 0; i<n;i++){
            int v;
            cin>>v;
            a.push_back(v);
        }
        sort(a.begin() , a.end());
        for(int i = 0; i<a.size() ; i++){
            if(a[i] != a[i+1]){
                if(a[i]%2 != a[i+1]%2 ){
                    cout<<"YES";
                    goto end;
                }
                if(a[i]%2 == 1 && a[i+1]%2 == 1){
                    int m = __gcd(a[i] , a[i+1]);
                    if(m == 1){
                        cout<<"YES";
                        goto end;
                    }
                }
            }
        }
        cout<<"NO";
        end:
        cout<<endl;
        continue;
    }
}