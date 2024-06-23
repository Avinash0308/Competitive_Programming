#include <iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	int test; 
	cin>>test;
	while(test--){
	    long long int n , k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    vector<int> v;
	    v.push_back(0);
	    v.push_back(0);
	    for(int i = 0; i<n ; i++){
	        if(s[i] == '0'){
	            v[0]++;
	        }
	        else{
	            v[1]++;
	        }
	    }
	    if(v[0] == v[1]){
	        cout<<"0"<<endl;
	    }
	    else{
	        if(v[0]>v[1]){
	            if((v[0]-v[1])%k == 0){
	                cout<<(v[0]-v[1])/k<<endl;
	            }
	            else{
	                cout<<((v[0]-v[1])/k)+1<<endl;
	            }
	        }
	        if(v[1]>v[0]){
	            if((v[1]-v[0])%k == 0){
	                cout<<(v[1]-v[0])/k<<endl;
	            }
	            else{
	                cout<<((v[1]-v[0])/k)+1<<endl;
	            }
	        }
	    }
	    
	}
	return 0;
}
