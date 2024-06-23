#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int a , b;
        cin>>a>>b;
        int c = a;
        int d = 1;
        int arr[a];
        for(int i = 0; i<=a ; i++){
            if(i%2 == 0){
                arr[i] = c;
                c--;
            }
            else{
                arr[i] = d;
                d--;
            }
        }
        d = 0;
        while(arr[d] != b){
            if(arr[d] == b){
                cout<<d<<endl;
            }
            else{
                d++;
            }
        }
    }
}
