#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include<set>
using namespace std;
void solveit(vector<int>a , vector<int>b ){
	int ans = 0 , q = 0;
	vector<int> ab;
	bool me = true;
	while(*min_element(a.begin() , a.end() ) > -1){
		 ab.push_back(*min_element(a.begin() , a.end()));
		for(int i = 0 ; i<a.size() ; i++){
			if(a[i] != ab[q]){
				if(a[i] >= b[i]){
					int x = (a[i] - ab[q])/b[i];
					a[i] -=  (x*b[i]);
					ans+=x;
				}
			}
		}
		set<vector<int>> s(a.begin() , a.end());
		if(s.size() == 1){
			me = false;
			cout<<ans<<endl;
			break;
		}
		if(q>0){
			if(ab[q] == ab[q-1]){
				break;
			}
		}
		q++;
	}
	if(me){
		cout<<"-1"<<endl;;
	}
}
int main() {
	vector<int> a;
	vector<int> b;
	int n;
	int ac;
	cin>>n;
	for(int i = 0 ; i<n ; i++){
		cin>>ac;
		a.push_back(ac);
	}
	for(int i = 0 ; i<n ; i++){
		cin>>ac;
		b.push_back(ac);
	}
	solveit(a , b );
}