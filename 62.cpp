#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    string s;
	    cin>>s;
	     long long int x = 0;
	    long long int z = 0;
	    for(int i = 0; i<s.length() ; i++){
	        if(s[i] == '0'){
	        x = x*2 ;
	        z = z*2 + 1;
	        }
	        else{
	            x = x*2 + 1;
	            z = z*2;
	        }
	    }
	    long long int res = log2(x/z);
	    cout<<res<<endl;
	}
	return 0;
}