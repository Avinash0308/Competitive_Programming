#include <iostream>
#include<bits/stdc++.h>
#include<numeric>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    int a , b;
	    cin>>a>>b;
	    float x;
	    if(a>b){
	        int me = b;
	        b = a;
	        a = me;
	    }
	    x = x/a;
	    int f = x;
	    int flag =1 ;
	    while(x != 1){
	        if(x != (float) f || f%2 != 0){
	            flag = 0;
	            break;
	        }
	        x/=2;
	        f= x;
	    }
	    if(flag){
	        cout<<"YES"<<endl;
	    }
	    if(!flag){
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
