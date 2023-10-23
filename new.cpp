#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    vector<long long int> weight(n);
	    for(long long int i = 0; i<n;i ++){
	        cin>>weight[i];
	    }
	    vector<long long int> load(n);
	    for(long long int i = 0; i<n;i ++){
	        cin>>load[i];
	    }
	    long long int left = 0, right = 0;
	    vector<long long int> pre(n);
	    vector<long long int> suf(n);
	    for(long long int i = 0; i<n; i++){
	        pre[i] = left;
	        suf[n-i-1] = right;
	        left += load[i] - weight[i];
	        right += load[n-i-1] - weight[n-i-1];
	    }
	    vector<long long int> ans(n);
	    for(long long int i = 0; i<n; i++){
	        left = pre[i];
	        right = suf[i];
	        ans[i] = max(left+right,load[i]) - weight[i];
	    }
	    for(long long int i = 0; i<n;i ++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}