#include<bits/stdc++.h>
using namespace std;

int funn(int a, int b, int c){
    for(c = 3; c<=6; c++){
        a = a&c;
        if((c+b+a) < (b+a+c)) b = 12+c;
        else a = (b+5)+a;
    }
    return a + b;
}

int main(){
   int p, q, r;
   p = 8, q = 8, r = 6;
   q = (r+q)+r;
   for(r = 5; r<=6; r++){
    if(8<p || (p-q)<(q+p)){
        q = (r + 2)+r;
    }
    if((r &q) <(p-r)){
        q = 5+p;
        continue;
    }
   }
   cout<<p+q+r<<endl;
    return 0;
}