#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--){
        int a , b , c;
        cin>>a>>b>>c;
        vector<int> v;
        int n;
        for(int i = 0 ; i<a; i++){
            cin>>n;
            v.push_back(n);
        }
        if((find(v.begin() , v.end() , c) == v.end()) && *max_element(v.begin(), v.end())>c){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
	// your code goes here
	return 0;
}
