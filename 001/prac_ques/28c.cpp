#include<bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    int a , b;
	    cin>>a>>b;
	    if(a>b){
	        int temp = a;
	        a = b;
	         b = temp;
	    }
	    if(b%a != 0){
	        cout<<"NO"<<endl;
	        goto end;
	    }
	    else{
	        int tem = b/a;
	        int me = log2(tem);
	        float m = log2(tem);
	        if(m == (float)me){
	            cout<<"YES"<<endl;
	            goto end;
	        }
	        else{
	            cout<<"NO"<<endl;
	            goto end;
	        }
	    }
	    end:
	    continue;
	}
	return 0;
}
