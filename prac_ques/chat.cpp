#include<bits/stdc++.h>
using namespace std;
int funct(int n){
    int c = 0;
    for(int i = n; i>0; i = i/2){
        for(int j = 0; j<i; j++){
            count++;
        }
    }
    return count;
}
int funct(int n){
    int c = 0;
    for(int i = n; i>0; i--){
        for(int j = i; j>0; j/=2){
            count++;
        }
    }
    return count;
}