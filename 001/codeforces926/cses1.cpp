#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int x;
    cin>>x;
    while (x != 1)
    {
        /* code */
        cout<<x<<" ";
        if(x%2) x = x*3 + 1;
        else x/=2;
    } 
    cout<<1<<endl;
return 0;
}