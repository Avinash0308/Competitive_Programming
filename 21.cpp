#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int a , b , x , y ,k;
        cin>>a>>b>>x>>y;
        y = abs(y-b);
        x = abs(x-a);
        for(int i = 2 ; i<=y && i<=x ; i++){
            if(y%i==0 && x%i==0){
                k = i;
            }
        }
         cout<<k-1<<endl;
} 
}
