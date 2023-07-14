#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int fact (long long int t){
    if(t == 0 || t == 1){
        return 1;
    }
    else{
        return t * fact(t-1);
    }
}
int main(){
    long long int x = fact(3);
    cout<<x<<endl;
return 0;
}