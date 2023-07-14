#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int a , b;
        cin>>a>>b;
        if(a<b){
            cout<<b-a<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
return 0;
}