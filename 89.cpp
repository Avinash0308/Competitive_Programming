#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    vector<long long> v1(n);
	    vector<long long> v2(n);
	    for(long long i = 0; i<n ; i++){
	        cin>>v1[i];
	    }
	    for(long long i = 0; i<n ; i++){
	        cin>>v2[i];
	    }
	    long long min1 = INT_MAX , max1 = INT_MIN;
	    long long min2 = INT_MAX , max2 = INT_MIN;
	    for(long long i = 0; i<n ; i++){
	        long long diff1 = max(max1,v1[i]) - min(min1,v1[i]);
	        long long diff2 = max(max1,v2[i]) - min(min1,v2[i]);
	        long long diff3 = max(max2,v2[i]) - min(min2,v2[i]);
	        long long diff4 = max(max2,v1[i]) - min(min2,v1[i]);
	        long long minim = min(min(diff1,diff2) , min(diff3,diff4));
	        if(diff2 == minim || diff4 == minim){
	            min1 = min(min1,v2[i]);
	            max1 = max(max1,v2[i]);
	            min2 = min(min2,v1[i]);
	            max2 = max(max2,v1[i]);
	        }
	        else{
	            min1 = min(min1,v1[i]);
	            max1 = max(max1,v1[i]);
	            min2 = min(min2,v2[i]);
	            max2 = max(max2,v2[i]);
	        }
	    }
	    cout<<min(max2-min2 , max1-min1)<<endl;
	}
	return 0;
}