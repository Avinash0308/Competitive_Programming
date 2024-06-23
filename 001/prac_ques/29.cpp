#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    long long int a;
	    cin>>a;
	    int x = 1 ,  v = 3  , flag =1 ;
	    while( v * v <= a){
	        if((a+x)%v == 0 && a>=2*v - x){
	            cout<<"YES"<<endl;
	            flag = 0;
	            break;
	        }
	        x--;
	        v++;
	    }
	    if(flag){
	        cout<<"NO"<<endl;
	    }
	    
	}
	return 0;
}
