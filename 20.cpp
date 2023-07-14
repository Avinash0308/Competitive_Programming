#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int test; 
	cin>>test;
	while(test--){
	    long long int n ;
	    vector<int> v;
	    int x;
	    for(int i = 0; i<n ; i++){
	        cin>>x;
	        v.push_back(x);
	    }
	    sort(v.begin() , v.end());
	    set<vector<int>> s(v.begin() , v.end());
	    if(s.size() == 1){
	        cout<<"0"<<endl;
	    }
	    else{
	        int arr[s.size()];
	        int ar[s.size()];
            int k = 0;
            for(int i = 0 ; i<n ; i++ ){
                arr[k] = 1;
                ar[k] = v[i];
                while(v[i] == v[i+1]){
                    arr[k]++;
                    i++;
                }
                k++;
            }
            // if(arr[s.size()-1]*ar[s.size()-1] >= )
	    }
	}
	return 0;
}
