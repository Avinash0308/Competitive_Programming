#include <iostream>
#include<vector>
using namespace std;
long long int factorial(long long int n){
    if(n ==1){
        return 1;
    }
    else{
        return (n%1000000007 * factorial((n)%1000000007-1)%1000000007)%1000000007;
    }
}
int main() {
	// your code goes here
	long long int n , c;
	cin>>n>>c;
	vector<long long int> v1;
	vector<long long int> v2;
	for(int i = 1; i<n ;i++){
	    long long int u , v;
	    cin>>u>>v;
	    v1.push_back(u);
	    v2.push_back(v);
	}
	if(n>c){
	    cout<<"0"<<endl;
	}
	else{
	    
	}
	return 0;
}
