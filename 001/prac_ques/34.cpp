#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	
	bool fascinating(int n) {
	    int a = n*2 , b = n*3;
	    vector<int> v;
	    while(n!=0 ){
	        v.push_back(n%10);
	        n/=10;
	        v.push_back(a%10);
	        a/=10;
	        v.push_back(b%10);
	        a/=10;
	    }
	    set<vector<int>> s(v.begin() , v.end());
	    if(s.size() == 9){
	        return true;
	    }
	    else{
	       return false;
	    }
	}
};
int main(){
    
return 0;
}