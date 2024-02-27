#include<bits/stdc++.h>
using namespace std;
long solve(int a){
    long ans = 0;
    for(int i = 1; i<=a; i++){
        long long int val = i;
        while(val){
            ans += val;
            val/=2;
        }
    }
    return ans;
}