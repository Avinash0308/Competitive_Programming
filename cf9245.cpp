#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i<n; i++){
            cin>>v[i];
        }
        int a = 0;
        while(a<n-1 && v[a] == v[a+1]) a++;
        int b = n-1;
        while(b > 0 && v[b] == v[b-1]) b--;
        if(v[0] == v[n-1]){
            if(a == n-1) cout<<0<<endl;
            else{
                cout<<b-a-1<<endl;
            }
        }
        else{
            cout<<min(n-1-a,b)<<endl;
        }
    }
return 0;
}