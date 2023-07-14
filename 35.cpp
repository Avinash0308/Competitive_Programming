#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:	
	
	vector<string> pattern(string S)
	{
	    // Your code goes here
	    vector<string> v;
	    for(int i = 0 ; i<S.length() ;i++){
	        string s;
	        for(int j = 0; j<S.length() - i ; j++){
	            s += S[j];
	        }
	        v.push_back(s);
	    }
	    return v;
	}

};
int main(){
    
return 0;
}