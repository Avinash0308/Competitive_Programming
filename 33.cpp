#include<iostream>
#include<bits/stdc++.h>
using namespace std;
   string average(int A[], int N)
    {
        int x = 0;
        for(int i = 0; i<N; i++){
            x+=A[i];
        }
        float f = (float)x/N;
        string s = x + " " + (int)f;
        return s;
    }
int main(){
    
return 0;
}