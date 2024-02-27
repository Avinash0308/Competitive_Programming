#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    int pt;
	    cin>>pt;
	    vector<int> ground;
	    vector<int> water;
	    for(int i = 0; i<pt ; i++){
	        int x;
	        cin>>x;
	        ground.push_back(x);
	    }
	    for(int i = 0; i<pt ; i++){
	        int x;
	        cin>>x;
	        water.push_back(x);
	    }
	    vector<int> v1(pt,0);
	    for(int i = 0; i<pt-1 ; i++){
	        for(int j = i+1; j<pt ; j++){
	            if(ground[i] > ground[j] || water[i] > water[j]){
	                v1[i]++;
	            }
	            if(ground[i] < ground[j] || water[i] < water[j]){
	                v1[j]++;
	            }
	        }
	    }
	    sort(v1.begin(),v1.end());
	    int result = 1;
	    int x = pt-1;
	    while(v1[x] == v1[x-1]){
	        x--;
	        result++;
	    }
	    cout<<result<<endl;
	}
	
	return 0;
}
