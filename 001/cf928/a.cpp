#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int pos = 1;
        while(pos*2 <= n) pos*= 2;
        cout<<pos<<endl;
    }
return 0;
}