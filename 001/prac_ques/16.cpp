#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int test; 
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0 ; i<n; i++){
	        cin>>arr[i];
	    }
	    sort(arr , arr+n);
	    vector<int> q;
	    int v = 0;
	    for(int i = 0; i<n ; i++){
	        q.push_back(1);
	        while(arr[i]==arr[i+1]){
	            q[v] += 1; 
	            i++;
	        }
	        v++;
	    }
	    v = 0;
	    for(int i = 0; i<q.size() ; i++){
	        if(q[i] > v){
	            v = q[i];
	        }
	    }
        for(int i = 0 ; i<q.size() ; i++){
            if(q[i] == v){
                if(v %2 == 1){
                    q[i] = ( q[i]/2) + 1;
                }
                else{
                    q[i]/=2;
                }
            }
        }
        v = 0;
	    for(int i = 0; i<q.size() ; i++){
	        if(q[i] > v){
	            v = q[i];
	        }
	    }
	    cout<<v<<endl;
	}
	return 0;
}
