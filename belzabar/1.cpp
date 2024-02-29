#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}
int is_belzabar_number(int num){
    int count = 0;
    for(int i = 2; (i*(i+20)) <= num; i++){
        if(prime(i)){
            count++;
        }
    }
    return count;
}
int main(){
    for(int i = 1; i<100; i++){
        if(prime(i))cout<<i<< " ";
    }
    cout<<is_belzabar_number(1000000)<<endl;
return 0;
}